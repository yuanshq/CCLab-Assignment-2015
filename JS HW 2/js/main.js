//taskArray
var taskArray = [];


//deletetask
var deleteTask = function(e){

	
};

//saveTask
var saveTask = function(){

};


//updateTasks
var updateTasks = function(){
	
	
};


//init
var init = function(){
	conosle.log("hey jquery!");

	//define button by id and wait for the click event
	$('#addButton').click(function(e){
		e.preventDefault();
		saveTask();
	});

	
};

//load listener
// $("selector").action()
// $() - turns whatever is inside () into an object
$(document).ready(init);