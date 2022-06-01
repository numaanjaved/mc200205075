document.write('<div class="main"></div>');
$(document).ready(console.log("JQuery Loaded"));
let body = document.body;

let main = document.querySelector('.main'); 
    $(main).addClass('mt-5').addClass('rounded').addClass('bg-white').addClass('container');

    let dispatchContainer = document.createElement('div');
    $(main).append(dispatchContainer);
        dispatchContainer.id = "dispatch-row";
        $(dispatchContainer).addClass('row').addClass('m-4');
        borderRoundedDark(dispatchContainer);
        // $(dispatchContainer).text('DispatchContainer');

        let dispatchDateContainer = document.createElement('div');
        $(dispatchContainer).append(dispatchDateContainer);
            dispatchDateContainer.id = "dispatchDateContainer";
            $(dispatchDateContainer).addClass('bg-warning').text('DispatchDateContainer');
            setGrid(dispatchDateContainer, 3, 4, 5, 6);
            $(dispatchDateContainer)
        
        let dispatchSpaceContainer = document.createElement('div');
        $(dispatchContainer).append(dispatchSpaceContainer);
            // $(dispatchSpaceContainer).addClass('col-6');
            setGrid(dispatchSpaceContainer, 6, 4, 2, 0);

        let dispatchCodeContainer = document.createElement('div');
        $(dispatchContainer).append(dispatchCodeContainer);
            dispatchCodeContainer.id = "dispatchCodeContainer";
            // $(dispatchCodeContainer).addClass('mt-4');
            $(dispatchCodeContainer).addClass('bg-warning').text('Dispatch Code: ');
            setGrid(dispatchCodeContainer, 3, 4, 5, 6);
            $(dispatchCodeContainer);
        
    let driverTruckSelectionContainer = document.createElement('div');
    $(main).append(driverTruckSelectionContainer);
        driverTruckSelectionContainer.id = "driver-truck-selection-row";
        $(driverTruckSelectionContainer).addClass('row').addClass('m-4');
        // borderRoundedDark(driverTruckSelectionContainer);

        let driverContainer = document.createElement('div');
        $(driverTruckSelectionContainer).append(driverContainer);
            driverContainer.id = 'driver-container';
            $(driverContainer).addClass('col-xl-4');
            $(driverContainer).addClass('col-md-6');
            $(driverContainer).text("Drivers:");

            let driverContainerInside = document.createElement('div');
            $(driverContainer).append(driverContainerInside);
                driverContainerInside.id = 'driver-container-inside';
                $(driverContainerInside).addClass('m-1');
                $(driverContainerInside).addClass('ml-0');
                borderRoundedDark(driverContainerInside);
                // $(driverContainerInside).text("Driver SubContainer");

                for(let i = 0; i < 20; ++i){
                    let driver = document.createElement('div');
                    $(driverContainerInside).append(driver);
                        driver.id = 'driver-'+(i+1);
                        $(driver).addClass('d-inline-block');
                        $(driver).addClass('driver');
                        $(driver).addClass('m-1');

                        driverImg = document.createElement("img");
                        $(driver).append(driverImg);
                        driverImg.src = "imgs/driverimage.jpg"
                }
               

        let truckContainer = document.createElement('div');
        $(driverTruckSelectionContainer).append(truckContainer);
            truckContainer.id = 'truck-container';
            $(truckContainer).addClass('col-xl-4');
            $(truckContainer).addClass('col-md-6');
            $(truckContainer).text("Trucks:");

            let truckContainerInside = document.createElement('div');
            $(truckContainer).append(truckContainerInside);
                truckContainerInside.id = 'truck-container-inside';
                $(truckContainerInside).addClass('m-1');
                borderRoundedDark(truckContainerInside);
                // $(truckContainerInside).text("Truck SubContainer");

                for(let i = 0; i < 8; ++i){
                    let truck = document.createElement('div');
                    $(truckContainerInside).append(truck);
                        truck.id = 'truck-'+(i+1);
                        $(truck).addClass('d-inline-block');
                        $(truck).addClass('truck');
                        $(truck).addClass('m-1');

                        let img = document.createElement('img');
                        $(truck).append(img);
                        img.src = "imgs/truck.png"
                }

        let driverTruckSelectorContainer = document.createElement('div');
        $(driverTruckSelectionContainer).append(driverTruckSelectorContainer);
            driverTruckSelectorContainer.id = 'dt-selection-container';
            $(driverTruckSelectorContainer).addClass('col-xl-4');
            $(driverTruckSelectorContainer).addClass('col-md-12');
            $(driverTruckSelectorContainer).text("Selection:");

            let driverTruckSelectionContainerInside = document.createElement('div');
            $(driverTruckSelectorContainer).append(driverTruckSelectionContainerInside);
                driverTruckSelectionContainerInside.id = 'dt-selection-container-inside';
                $(driverTruckSelectionContainerInside).addClass('m-1');
                borderRoundedDark(driverTruckSelectionContainerInside);
                // $(driverTruckSelectionContainerInside).text("Driver Truck Selection SubContainer");

    let containsContainer = document.createElement('div');
    $(main).append(containsContainer);
        containsContainer.id = "contains-container-row";
        $(containsContainer).addClass('row').addClass('m-4');

        let containorContainer = document.createElement('div');
        $(containsContainer).append(containorContainer);
            containorContainer.id = 'containor-container';
            $(containorContainer).addClass('col-xl-6');
            $(containorContainer).addClass('col-md-6');
            $(containorContainer).text("Containers:");

            let containorContainerInside = document.createElement('div');
            $(containorContainer).append(containorContainerInside);
                containorContainerInside.id = 'containor-container-inside';
                $(containorContainerInside).addClass('m-1');
                borderRoundedDark(containorContainerInside);
                for(let i = 0; i < 12; ++i){
                    let containor = document.createElement('div');
                    $(containorContainerInside).append(containor);
                        containor.id = "containor-"+(i+1);
                        $(containor).addClass("containor").addClass("d-inline-block").addClass("m-1");

                        let containorImg = document.createElement("img");
                        $(containor).append(containorImg);
                            containorImg.src = "imgs/container.png"
                }
                
        
        let containorSelectionContainer = document.createElement('div');
        $(containsContainer).append(containorSelectionContainer);
            containorSelectionContainer.id = 'containor-selection-container';
            $(containorSelectionContainer).addClass('col-xl-6');
            $(containorSelectionContainer).addClass('col-md-6');
            $(containorSelectionContainer).text("Container Truck Selection:");

            let containorSelectionContainerInside = document.createElement('div');
            $(containorSelectionContainer).append(containorSelectionContainerInside);
                containorSelectionContainerInside.id = 'containor-selection-container-inside';
                $(containorSelectionContainerInside).addClass('m-1');
                borderRoundedDark(containorSelectionContainerInside);
    
    let buttonsContainer = document.createElement('div');
    $(main).append(buttonsContainer);
        buttonsContainer.id = "buttons-container-row";
        $(buttonsContainer).addClass('row').addClass('m-4');

        let buttonReset = document.createElement('button');
        $(buttonsContainer).append(buttonReset);
            buttonReset.id = "button-all-reset";
            $(buttonReset).text("Reset");
            $(buttonReset).addClass("col-3");
            $(buttonReset).addClass("btn");
            $(buttonReset).addClass("btn-primary");
