//-----------------------------------------------
//Get the enchant.js game working

//1 - Start enchant.js
enchant();	//Export all the library classes gloablly,
			//allows you to use all classes from enchant.js

//2 - On document load	//Invoke the function once the HTML document is doine loading.
						//Initialize game insdie the function
window.onload = function(){
	//3 - Starting Point	//Creat an instance of game class
	var game = new Game(1347, 760);
	//4 - Preload resources
	game.preload('res/BG.png',
				 'res/mickeySheet.png',
				 'res/Snowball.png');
	//5 - Game settings
	game.fps = 30;	//30fps per second, maximum fps
	game.scale = 1;
	game.onload = function(){
			//6 - Game object's onload event will be invoked once Game finishes loading
			console.log("Skeeing Mickey");

			var scene = new SceneGame();//instantiate a SceneGame object, and add it to the scene stack
			//Start scene
			game.pushScene(scene);//push the scene onto the game's scene stack,
								  //make it active scene
	}
	//7 - Start
	game.start();
	//enchant.js comes with object-oriented framework(OOP)
	//SceneGame, create SceneGame tha is a subclass of Scene,
	//so Scene is the superclass of SceneGame
	var SceneGame = Class.create(Scene, {
		//The main gameplay scene(Constructor of Scene)
		initialize: function(){
			var game, label, bg, mickey, snowballgroup;

			//(1) - Call superclass constructor, do initialization
			Scene.apply(this);
			//(2) - Access to the game singleton instance,assign the
			//singleton Game instance to the game variable for later use
			game = Game.instance;
			//(3) - Create child nodes
			// Label
			label = new Label("Skeeing Mickey");
			label = new Label('SCORE<br>0');
			label.x = -50;
			label.y = 32;
			label.color = 'black';
			label.font = '25px strong';
			label.textAlign = 'center';
			label._style.textShadow ="-1px 0 black, 0 1px black, 1px 0 black, 0 -1px black";
			this.scoreLabel = label;
			bg = new Sprite(1347, 760);//Create a Sprite node
			bg.image = game.assets['res/BG.png'];//background image
			bg.x = game.width/2 - bg.width/2

			mickey = new Mickey()//instantiate an instance of the Mickey class
			//set the mickey's position
			mickey.x = game.width/2 - mickey.width/2;
			mickey.y = 280;
			this.mickey = mickey;//???

			//snowballgroup
			snowballgroup = new Group();
			this.snowballgroup = snowballgroup;

			//(4) - Add child nodes
			//addChild: the node you add will become one of the scene's child nodes
			//In enchant.js, the framework will draw a newly-added
			//node on top of those that were added previously.
			this.addChild(bg);	//this refers to SceneGame	//add bg node to the scene
			this.addChild(snowballgroup);
			this.addChild(mickey);//add mickey to th screen,
								   //on top of the background, but under the label
			this.addChild(label);
			//Touch listener
			this.addEventListener(Event.TOUCH_START, this.handleTouchControl);//Touch/click Detection
			//Update
			this.addEventListener(Event.ENTER_FRAME, this.update);//To make an snowball appear every three seconds
			//Instance variables
			this.generateSnowballTimer = 0;//timer to generate an snowball
			//scoretimer
			this.scoreTimer = 0;
			this.score = 0;

		},

		handleTouchControl: function(evt){
			var laneWidth, lane;
			laneWidth = 1347/3;//divide the screen’s width by 3 to get the width of each section/lane.
			lane = Math.floor(evt.x/laneWidth);//evt.x is the touch position
			//The Math.floor() function returns the largest integer less than or equal to a given number.
			//Here returns 0,1 or 2 to lane
			lane = Math.max(Math.min(2,lane),0);
			//The Math.max() function returns the largest of zero or more numbers.
			this.mickey.switchToLaneNumber(lane);
			//Once u determine which lane was clicked/touched, mickey moves to that lane.
			//switchToLaneNumber method goes in Mickey class and not SceneGame class
		},

		update: function(evt){
			// Score increase as time passes
			this.scoreTimer += evt.elapsed * 0.001;
			if (this.scoreTimer >= 1) {
    			this.setScore(this.score + 1);
    			this.scoreTimer -= 1;
			}

			//check if it's time to create a new set of snowballs
			this.generateSnowballTimer += evt.elapsed * 0.001;
			if(this.generateSnowballTimer >= 0.5){
				var snowball;
				this.generateSnowballTimer -= 0.5;
				snowball = new Snowball(Math.floor(Math.random()*3));
				this.snowballgroup.addChild(snowball);
			}

			// Check collision
			for (var i = this.snowballgroup.childNodes.length - 1; i >= 0; i--) {
			    var Snowball;
			    Snowball = this.snowballgroup.childNodes[i];
			    if (Snowball.intersect(this.mickey)){
			        this.snowballgroup.removeChild(Snowball);
			        break;
			    }
			}
		},

		setScore: function (value) {
   			this.score = value;
    		this.scoreLabel.text = 'SCORE<br>' + this.score;
}
	});

	//Mickey
	var Mickey = Class.create(Sprite, {
		//The player character
		initialize: function(){
			//(1) - Call superclass constructor
			Sprite.apply(this, [339, 425]);
			this.image = Game.instance.assets['res/mickeySheet.png'];
			//(2) - Animate
			this.animationDuration = 0;//timer for animation
			//you tell the mickey to listen for the ENTER_FRAME event,
			//and call a method named updateAnimation every time this event occurs
			this.addEventListener(Event.ENTER_FRAME, this.updateAnimation);
			//ENTER_FRAME is an event that is fired every frame
		},

		//For the ENTER_FRAME event, one item of information you can access
		//is the amount of time that has passed since the last frame.
		//This information can be accessed through the elapsed property.
		updateAnimation: function(evt){
			this.animationDuration += evt.elapsed * 0.001;
			//The elapsed property stores time in milliseconds, so convert it to seconds
			//Use the animationDuration variable to keep track of how much time has passed in seconds.

			//Mickey flaps his wings every 0.25 seconds.
			if (this.animationDuration >= 0.25) {
				//Sprite node in enchant.js treats the image you assign as a sprite sheet.
				//It will use the size you’ve given as its frame size, and assign an index number to each frame. (0,1)
				//The index will start from 0, counting from left to right and top to bottom.
				this.frame = (this.frame + 1) % 2;//change the frame between 0 and 1
				this.animationDuration -= 0.25;
			}
		},

		switchToLaneNumber: function(lane){
			//calculate the x position for the mickey, given the lane number
			var targetX = 674 - this.width/2 + (lane-1)*250;
			this.x = targetX;
		}
	});

	//Snowball
	//If you add the snowball to the scene, the scene becomes the parent node of the snowball.
	var Snowball = Class.create(sprite, {
		//The snowball that the mickey must avoid
		initialize: function(lane){
			//Call superclass constructor
			Sprite.apply(this, [283, 282]);
			this.image = Game.instance.assets['res/Snowball.png'];
			this.rotationSpeed = 0;
			this.setLane(lane);
			this.addEventListener(Event.ENTER_FRAME, this.update);
		},

		setLane: function(lane){
			var game, distance;
			game = Game.instance;
			distance = 300;


			//The Math.random() function returns a floating-point, pseudo-random number in the range [0, 1)
			this.rotationSpeed = Math.random() * 100 - 50;
			//the position of Sprite
			this.x = game.width/2 - this.width/2 + (lane - 1) * distance;
			this.y = this.height;
			this.rotation = Math.floor(Math.random() * 360);
		},

		update: function(evt){
			var ySpeed, game;

			game = Game.instance;
			ySpeed = 300;

			this.y += ySpeed * evt.elapsed * 0.001;
			this.rotation += this.rotationSpeed * evt.elapsed * 0.001;
			if(this.y > game.height){
				//once snowball moves beyond the bottom of the screen, remove it from the scene
				this.parentNode.removeChild(this);
			}
		}
	});

	// // SceneGameOver
	// var SceneGameOver = Class.create(Scene, {
	//     initialize: function(score) {
	//         var gameOverLabel, scoreLabel;
	//         Scene.apply(this);
	//         this.backgroundColor = 'black';
	//         // Game Over label
	// 		gameOverLabel = new Label("GAME OVER<br>Tap to Restart");
	// 		gameOverLabel.x = 8;
	// 		gameOverLabel.y = 128;
	// 		gameOverLabel.color = 'white';
	// 		gameOverLabel.font = '32px strong';
	// 		gameOverLabel.textAlign = 'center';
	// 		// Score label
	// 		scoreLabel = new Label('SCORE<br>' + score);
	// 		scoreLabel.x = 9;
	// 		scoreLabel.y = 32;
	// 		scoreLabel.color = 'white';
	// 		scoreLabel.font = '16px strong';
	// 		scoreLabel.textAlign = 'center';
	// 		// Add labels
	// 		this.addChild(gameOverLabel);
	// 		this.addChild(scoreLabel);
	// 		// Listen for taps
	// 		this.addEventListener(Event.TOUCH_START, this.touchToRestart);
	//     },

	//     touchToRestart: function(evt) {
	// 	    var game = Game.instance;
	// 	    game.replaceScene(new SceneGame());
	// 	}
	// });



















};
//-----------------------------------------------
