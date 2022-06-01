let drivers = $("#driver-container-inside").children(".driver");

for(let i = 0; i < drivers.length; ++i){
    $(drivers[i]).data("data", {
        type: "driver",
        id: i+1,
        firstName: "first",
        lastName: "last"
    });
    // console.log($(drivers[i]).data());
    let name = document.createTextNode($(drivers[i]).data("data").firstName + " " + $(drivers[i]).data("data").lastName);
    $(drivers[i]).append(name);
}

let trucks = $("#truck-container-inside").children(".truck");

for(let i = 0; i < trucks.length; ++i){
    let first3Alphabets = createRandomString(3);
    let fourNumbers = createRandomNumbers(4);
    $(trucks[i]).data("data", {
        type: "truck",
        id: i+1,
        vehicleNumber: first3Alphabets + fourNumbers,
    });
    // console.log($(trucks[i]).data());
    $(trucks[i]).append($(trucks[i]).data("data").vehicleNumber);
}
let containers = $("#containor-container-inside").children(".containor");

for(let i = 0; i < containers.length; ++i){
    $(containers[i]).data("data", {
        type: "container",
        id: i+1,
        containerNumber: createContainerNumber(i+1),
    });
    // console.log($(containers[i]).data());
    $(containers[i]).append($(containers[i]).data("data").containerNumber);
}