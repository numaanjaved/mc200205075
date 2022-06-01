    // console.log(document.currentScript.src);
    // document.body.style.backgroundColor = '#F0F2F5';
    // document.body.style.fontFamily = 'Arial';
    // document.body.style.overflowX = "hidden";
    document.write("<div class='main'></div>");

    let modal = document.createElement('div');
    let obesiveLayer = document.createElement('div');    
    let signupContainer = document.createElement('div');
    let signup = document.createElement('div');
    let signupHeader = document.createElement('div');
    let signupHeading = document.createTextNode('Student Form');
    let signupClose = document.createElement('i');
    let signupMain = document.createElement('div');
    let signupForm = document.createElement('form');
    let signupFormThird = document.createElement('div');
    let signupFormThirdLabel = document.createElement('label');
    let signupFormThirdLabelText = document.createTextNode('Date: ');
    let signupInputDate = document.createElement('input');   
    let signupInputProgram = document.createElement('select');
    let signupFormFourth = document.createElement('div');
    let signupFormFourthLabel = document.createElement('label');
    let signupFormFourthLabelText = document.createTextNode('About Me: ');
    let signupFormTextArea = document.createElement('textarea');
    let signupFormFifth = document.createElement('div');
    let signupFormFifthLabel = document.createElement('label');
    let signupFifthLabelText = document.createTextNode("Image");
    let signupFormFifthInput = document.createElement('input');
    let signupFormSixth = document.createElement('div');
    let signupFormSixthLabel = document.createElement('label');
    let signupSixthLabelText = document.createTextNode("Image");
    let signupFormSixthInput = document.createElement('img');
    let signupDelete = document.createElement("div");
    let signupFooter = document.createElement('div');
    let submitFormReset = document.createElement('button');
    let submitFormResetText = document.createTextNode("Reset");
    let submitFormInput = document.createElement('input');

    cssForm();

    
    
    setID(signupContainer, "signup-container");
    setID(signupForm, "add-student-form");
    setID(signupFormSixth, "image-student");
    setID(signupFormSixthInput,"form-image");
    setID(signupDelete, "delete-student");
    setID(submitFormReset,"form-reset");

    setName(signupInputProgram, "program");
    setName(signupFormTextArea, "aboutMe");    
    setName(signupFormFifthInput, "image");
    setType(signupFormFifthInput, "file");
    setType(submitFormInput,"submit");
    setValue(submitFormInput,"Add");
    setRowsCols(signupFormTextArea, "10", "56");
    setInputAttributes(signupInputDate,"date", "date","Date");
    
    
    modal.appendChild(obesiveLayer);            
    signupFormThirdLabel.appendChild(signupFormThirdLabelText);
    signupFormThird.appendChild(signupFormThirdLabel);               
    signupFormThird.appendChild(signupInputDate);                    
    signupFormThird.appendChild(signupInputProgram);
    
    signupFormFourthLabel.appendChild(signupFormFourthLabelText);
    signupFormFourth.appendChild(signupFormFourthLabel);
    signupFormFourth.appendChild(signupFormTextArea);
    
    signupFormFifthLabel.appendChild(signupFifthLabelText);
    signupFormFifth.appendChild(signupFormFifthLabel);
    signupFormFifth.appendChild(signupFormFifthInput);
    
    signupFormSixthLabel.appendChild(signupSixthLabelText);
    signupFormSixth.appendChild(signupFormSixthLabel);
    signupFormSixth.appendChild(signupFormSixthInput);
    
    signupMain.appendChild(signupForm);
    
    submitFormReset.appendChild(submitFormResetText);
    signupFooter.appendChild(submitFormReset);
    signupFooter.appendChild(submitFormInput);
    
    createModalInnerDiv(signupContainer, signup);
    createModalInnerDivHeader(signup, signupHeader, signupHeading, signupClose);
    createModalDivider(signup);
    createModalMain(signup, signupMain);
    createFormName(signupForm);
    createFormName(signupForm, "father-", "Father's ");
    signupForm.appendChild(signupFormThird); 
    signupForm.appendChild(signupFormFourth);
    signupForm.appendChild(signupFormFifth);
    signupForm.appendChild(signupDelete);
    signupForm.appendChild(signupFormSixth);
    createModalDivider(signup);
    signup.appendChild(signupFooter);
    signupContainer.appendChild(signup);
    modal.appendChild(signupContainer);
    
    for(let i = 0; i < 3; ++i){
        let text; let value;
        let signupInputProgramOption = document.createElement('option');
        if(i == 0){
            text = "Select Program";
            value = "";
        }
        else if(i == 1){
            text = "Bachelors in Computer Science";
            value = i;
        }
        else{
            text = "Masters in Computer Science";
            value = i;
        }                            
        signupInputProgramOption.setAttribute("value", value);    
        
        if(value == ""){
            signupInputProgramOption.setAttribute("hidden", "");
            hide(signupInputProgramOption);
        }
        let signupInputProgramOptionText = document.createTextNode(text);
        
        signupInputProgramOption.appendChild(signupInputProgramOptionText);

        signupInputProgram.appendChild(signupInputProgramOption);
    }       
    
    
     let viewContainer = document.createElement("div");
     viewContainer.id = "view-container";
     let view = document.createElement('div');
     view.id = "view";
    createModalInnerDiv(viewContainer, view);
    

    
    let viewHeader = document.createElement('div');
    let viewHeading = document.createTextNode('Student View');
    let viewClose = document.createElement('i');
    createModalInnerDivHeader(view, viewHeader, viewHeading, viewClose);
    createModalDivider(view);
    let viewMain = document.createElement('div');
    createModalMain(view, viewMain);
    let viewFirstRowDiv = document.createElement("div");
        viewFirstRowDiv.classList.add("view-first-row");

    let viewImageDiv = document.createElement("div");
        viewImageDiv.classList.add("image-container");
    viewFirstRowDiv.appendChild(viewImageDiv);

    let viewNameDiv = document.createElement("div");
        viewNameDiv.classList.add("name-container");
    
    
    let viewMainRollNoDiv = document.createElement("div");
        viewMainRollNoDiv.classList.add("rollNo-container");
    let viewMainNameDiv = document.createElement("div");
        viewMainNameDiv.classList.add("main-name-container");
    let viewFatherNameDiv = document.createElement("div");
        viewFatherNameDiv.classList.add("father-name-container");
    
    viewNameDiv.appendChild(viewMainRollNoDiv);
    viewNameDiv.appendChild(viewMainNameDiv);
    viewNameDiv.appendChild(viewFatherNameDiv);
    viewFirstRowDiv.appendChild(viewNameDiv);
    
    
                        
    viewMain.appendChild(viewFirstRowDiv);
    
    let viewSecondRowDiv = document.createElement("div");
        viewSecondRowDiv.classList.add("view-second-row");
   
    let viewSemester = document.createElement("div");
        viewSemester.classList.add("view-semester-container");
        viewSemester.classList.add("float-left");

    let viewProgram = document.createElement("div");
        viewProgram.classList.add("view-program-container");
        viewProgram.classList.add("float-right");

    viewSecondRowDiv.appendChild(viewSemester);
    viewSecondRowDiv.appendChild(viewProgram);

    viewMain.appendChild(viewSecondRowDiv);
    let viewThirdRowDiv = document.createElement("div");
        viewThirdRowDiv.classList.add("view-third-row");
    
    let viewAboutMeHeading = document.createElement("div");
        viewAboutMeHeading.classList.add("view-aboutMe-heading");
        viewAboutMeHeading.classList.add("float-left");
    viewThirdRowDiv.appendChild(viewAboutMeHeading);
    
    let viewAboutMeDiv = document.createElement("div");
        viewAboutMeDiv.classList.add("view-aboutMe-container");
        viewAboutMeDiv.classList.add("float-right");
    viewThirdRowDiv.appendChild(viewAboutMeDiv);
    
    viewMain.appendChild(viewThirdRowDiv);

    

    document.body.appendChild(modal);

signupFormFifthInput.addEventListener("change", function(event){
    let img = document.querySelector("#form-image");
        img.src = URL.createObjectURL(event.target.files[0]);
        displayBlock(signupFormSixth);
        
});
let form = signup.querySelector('form');
let inputs = form.elements;

for(let i = 0; i < inputs.length; ++i){
    inputs[i].style.border = "1px solid black";
} 


let main = document.querySelector(".main");
    main.innerHTML = "<button class='actions'>Actions</button><div><table class='data'></table></div>";
    let divMenu = document.createElement('div');
        divMenu.classList.add("menu");

    main.appendChild(divMenu);
    
    let menu = document.querySelector(".menu");
        hide(menu);
        let divSubMenu = document.createElement('div');
        let subMenuText = document.createTextNode("Add Student");
        divSubMenu.appendChild(subMenuText);
        
        menu.appendChild(divSubMenu);
        divSubMenu.classList.add("subMenu");
    
        let subMenu = menu.querySelector(".subMenu");    


let actions = document.querySelector(".actions");
    toggleMenu(actions, menu);

    var RowsCount = 0;
    subMenu.addEventListener("click", openSubMenu);
    signupClose.addEventListener("click", closeSignup);
    viewClose.addEventListener("click", closeView);
    submitFormReset.addEventListener("click", formReset);

    function openSubMenu(){
        // Add Functionality
        form.id = "add-student-form";
        replaceContainerforNotView(modal);
        hide(menu);
        displayBlock(modal);
        resetButton = document.querySelector("#form-reset");
        if(resetButton.classList.contains("d-none")){
            displayBlock(resetButton);
        }
        signupInputDate.removeAttribute("readonly");
        signupInputProgram.removeAttribute("readonly");
        signupInputProgram.removeAttribute("aria-disabled");
        signupInputProgram.style.removeProperty("pointer-events");
        signupInputProgram.style.removeProperty("touch-action");
        submitFormInput.value = "Add";
        submitFormInput.type = "submit";
        hideDoubleDiv(form, "delete", "image");
        ++RowsCount;
    }
    function closeSignup(){
        hide(modal);
        formReset(); 
    }
    function closeView(){
        viewImageDiv.innerHTML = '';
        closeSignup(); 
    }
    function formReset(){
        signupForm.reset();
        hide(signupFormSixth);
        let data = form.elements;
        for(let i = 0; i < data.length; ++i){
            resetValidate(data[i]);
        }        
    }

    function cssForm(){
        obesiveLayer.classList.add("obesive-layer");
        signupFooter.classList.add("signup-footer");
        hide(modal);
        hide(signupFormSixth);
        hide(signupDelete);
        signupInputDate.classList.add("input-date");
        // setInputStyles(signupInputDate,"10px","calc(50% - 85px)","2px 5px");
        signupFormThird.classList.add("input-third-row");
        signupInputProgram.classList.add("input-program");
        signupInputProgram.classList.add("float-right");
        signupFormFourth.classList.add("input-fourth-row");
        setMargin(signupFormFourthLabel, "10px");
        signupFormTextArea.classList.add("input-textarea");
        setMargin(signupFormFifthLabel, "10px");
        signupFormFifthInput.classList.add("input-image");
        setMargin(signupFormSixthLabel, "10px");
        signupFormSixthInput.classList.add("file-image");
        setHeight(signupFormSixthInput,"300px");
        
        setFooter(submitFormReset, "5%", "35%");
        setFooter(submitFormInput, "65%", "35%");   
    }

    function pageView(RollNo){
        replaceContainerforView(modal);
        view.id = "view-"+RollNo;
        settingValuesInView(RollNo);
    }
    function pageUpdate(RollNo){
        replaceContainerforNotView(modal);
        if(!form.id.includes("update")){      
            form.id = "update-student-form-"+RollNo; 
            signupInputDate.setAttribute("readonly", "");
            signupInputProgram.setAttribute("readonly", "");
            signupInputProgram.setAttribute("aria-disabled", true);
            if(signupInputProgram.getAttribute("readonly")){
                signupInputProgram.style.pointerEvents = "none";
                signupInputProgram.style.touchAction = "none";
                signupInputProgram.addEventListener("keydown", function(event){
                    event.preventDefault();
                    return true;
                });
            }
            
            submitFormInput.value = "Update";
            submitFormInput.type = "submit";                                              
        }else{
            form.id = "update-student-form-"+RollNo; 
        }
        resetButton = document.querySelector("#form-reset");
        if(resetButton.classList.contains("d-none")){
            displayBlock(resetButton);
        }
        
        signupInputDate.setAttribute("readonly", "");
        signupInputProgram.setAttribute("readonly", "");
        signupInputProgram.setAttribute("aria-disabled", true);
        signupInputProgram.style.pointerEvents = "none";
        signupInputProgram.style.touchAction = "none";
        
        hideDoubleDiv(form, "delete", "image");                      
        settingValuesInUpdate(RollNo);
    }
    function pageDelete(RollNo){
        replaceContainerforNotView(modal);
        if(!form.id.includes("delete")){                           
            form.id = "delete-student-form-"+RollNo;                            
        }
        else{
            form.id = "delete-student-form-"+RollNo;
        }
        resetButton = document.querySelector("#form-reset");
        hide(resetButton);
        showOnlyDiv(form,"delete");
        divDelete = signup.querySelector("#delete-student");
        
        displayBlock(divDelete);
        signupDelete.innerHTML = `Do you want to delete the student ${RollNo}?`;
        submitFormInput.type = "button";
        submitFormInput.value = "Delete";      
    }
    signupInputProgram.addEventListener("keydown", function(event){
        if(form.id.includes("update")){
            event.preventDefault();                
        }     
        return true;       
    });