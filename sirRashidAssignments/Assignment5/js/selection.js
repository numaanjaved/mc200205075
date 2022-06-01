let draggableOptions = {
    addClasses: false, //this will stop adding a ui-draggable class
    containment: ".main", // this will contain the driver to a specific location 
    cursor: "move", // this will change the cursor to move 
    opacity: 0.5, // this will change the opacity
    helper: "clone", // this will create a clone of driver 
<<<<<<< HEAD
    revert: "invalid", // this will revert changes
});
$(".truck").draggable({
    addClasses: false,
    containment: ".main",
    cursor: "move",
    helper: "clone",
    opacity: 0.5,
    revert: "invalid",
});
let truckCount = 0;
$("#dt-selection-container-inside").droppable({
    // accept: ".truck",
    drop: function(event, ui){
        $("#truck-container-inside #dt-selection-container-inside").sortable().disableSelection();       
        let draggedInput = $(ui.draggable).clone();
        if(draggedInput.hasClass("truck")){
            if(truckCount < 2){
                $(ui.draggable).addClass("border").addClass("border-warning");
                $(this).append(draggedInput);
                ++truckCount;
                console.log("count = " + truckCount); 
            }
            else{
                event.preventDefault();
            }
        }        
    },
});
=======
    revert: "invalid", // this will revert to the original position where the object was already placed.
    disabled: false
}

function dropItem(selected, count, target){
    $(target).droppable({
        accept: selected,
        drop: function(event, ui){
            itemDrop(selected, count, event, ui); //a function is called where drop is taking place.
            
        }
    });
}
>>>>>>> 50cd190c5376897b57adde5ef4c80a66078fb34f

function switchDrag(){
    //its work in progress
}
$(".driver").draggable(draggableOptions);
$(".truck").draggable(draggableOptions);
$(".containor").draggable(draggableOptions);
// $("#dt-selection-container-inside .truck").draggable(draggableOptions); //truck selected from the first row is made draggable to be sent to second row 

function itemDrop(item, count, event, ui){
    console.log("item : ");
    console.log(item);
    console.log("count : ");
    console.log(count);
    console.log("event target: ");
    console.log(event.target);
    let draggedInput = $(ui.draggable).clone(); // this code created a variable with clone of dragged item 
    $(draggedInput).data("data", $(ui.draggable).data("data"));
    draggedChildren = $(ui.draggable).children("div");
    draggedInputChildren = $(draggedInput).children('div');
    if(draggedChildren.length > 0){
        for(let i = 0; i < draggedChildren.length; ++i){
            $(draggedInputChildren[i]).data("data", $(draggedChildren[i]).data());
            // console.log($(draggedInputChildren[i]).data("data").data);
        }
    }
    // console.log($(ui.draggable).attr("id"));

    let draggedItems = $(event.target).children(item); // this variable here is used to check how many items are being dragged to selection area
    // console.log("eventTarget = ");
    // console.log(event.target);
    // console.log("ui.draggable = ");
    // console.log(ui.draggable);
    if(draggedItems.length < count){ //this will check whether the dragged items are less than the count specified or more
        let repeated = false; // boolean to check whether the item is repeated or not 
        for(let i = 0; i < draggedItems.length; ++i){  //loop to check out whether the item is already dragged 
            if($(ui.draggable).attr("id") == $(draggedItems[i]).attr("id")){
                repeated = true;
                //break;
            }            
        }
        if(repeated == true){ //if item is repeated than get out of the function
            return;
        }        
        //this construct is used to append trucks if only the dragged trucks are not more than 2.
        $(ui.draggable).addClass("border").addClass("border-warning"); //to flag which trucks are being put into the selection container div 
            $(ui.draggable).draggable({ // disable the dragging property of original
                disabled: true
            }).droppable({ //disable the dropping property of original
                disabled: true
            });
        
        $(event.target).append(draggedInput); // add the clone of dragged input to the target.
        if(item == ".truck"){  //if the parameter item is truck 
            $.notify("Truck selected successfully", "success");  
            driverDroppable(); // this function is being called when the item is a truck
        }
        if(item == "#dt-selection-container-inside .truck"){ // the parameter item is truck inside the selection div 
            $.notify("Truck with driver is selected successfully", "success");            
        }
        if(item == ".driver"){ //the parameter item is driver 
            $.notify("Driver added to Truck successfully", "success");  
        }
        if(item == ".containor"){ //the parameter item is containor
            $.notify("Container added to Truck successfully", "success");
        }
        selectWholeTruck(); //this function will select the whole truck to be sent to the dispatch selection container, where container will also be selected
    }
    else{
        event.preventDefault();
    }
    // console.log(ui.draggable);
}
function selectWholeTruck(){
    
    if($("#dt-selection-container-inside .truck").children(".driver").length == 0){ // if there is no driver selected in the truck.
        $("#dt-selection-container-inside .truck").draggable({ //the truck is disabled from dragging 
            disabled: true
        });
        return; //returning call so that the function do not proceed further.
    }
    //upon success
    $("#dt-selection-container-inside .truck").draggable(draggableOptions);
    //dropping items in containor selection area 
    dropItem("#dt-selection-container-inside .truck", 1, "#containor-selection-container-inside");
    dropItem(".containor", 1, "#containor-selection-container-inside .truck");

    
}
//The code downward is used to drop a truck in the driver truck selection 
dropItem(".truck", 2, "#dt-selection-container-inside");
// console.log($("#dt-selection-container-inside").children(".truck").data());


function driverDroppable(){
    dropItem(".driver", 2, "#dt-selection-container-inside .truck");
}

$("#button-all-reset").click(function(){
    // console.log("works");
    $("#dt-selection-container-inside").empty();
    $("#containor-selection-container-inside").empty();
    $(".driver").removeClass("border-warning").removeClass('border').draggable({
        disabled: false
    });
    $(".truck").removeClass("border-warning").removeClass('border').draggable({
        disabled: false
    });
    $(".containor").removeClass("border-warning").removeClass('border').draggable({
        disabled: false
    });

});