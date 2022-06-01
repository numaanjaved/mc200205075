    // console.log(document.currentScript.src);
    document.body.style.backgroundColor = '#F0F2F5';
    document.body.style.fontFamily = 'Arial';
    document.body.style.overflowX = "hidden";
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
    setInputAttributes(signupFormSixthInput, "10px","calc(80% - 30px)","5px");
    
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
        setHeight(viewFirstRowDiv, "100px");

    let viewImageDiv = document.createElement("div");
        setHeightWidth(viewImageDiv, "150px", "150px");
        viewImageDiv.style.float = "left";
    viewFirstRowDiv.appendChild(viewImageDiv);

    let viewNameDiv = document.createElement("div");
        setHeightWidth(viewNameDiv, "150px","calc(100% - 165px)");
        viewNameDiv.style.float = "right";
    
    
    let viewMainRollNoDiv = document.createElement("div");
        setHeightWidth(viewMainRollNoDiv, "50px", "100%");
    let viewMainNameDiv = document.createElement("div");
        setHeightWidth(viewMainNameDiv, "50px", "100%");
    let viewFatherNameDiv = document.createElement("div");
        setHeightWidth(viewFatherNameDiv, "50px", "100%");
    
    viewNameDiv.appendChild(viewMainRollNoDiv);
    viewNameDiv.appendChild(viewMainNameDiv);
    viewNameDiv.appendChild(viewFatherNameDiv);
    viewFirstRowDiv.appendChild(viewNameDiv);
    
    
                        
    viewMain.appendChild(viewFirstRowDiv);
    
    let viewSecondRowDiv = document.createElement("div");
    setHeight(viewSecondRowDiv, "100px");
   
    let viewSemester = document.createElement("div");
    setHeightWidth(viewSemester, "100%", "50%");
    viewSemester.style.float = "left";

    let viewProgram = document.createElement("div");
    setHeightWidth(viewProgram, "100%", "50%");
    viewProgram.style.float = "right";

    viewSecondRowDiv.appendChild(viewSemester);
    viewSecondRowDiv.appendChild(viewProgram);

    viewMain.appendChild(viewSecondRowDiv);
    let viewThirdRowDiv = document.createElement("div");
    setHeight(viewThirdRowDiv, "150px");
    
    let viewAboutMeHeading = document.createElement("div");
        setHeightWidth(viewAboutMeHeading, "150px", "100px");
        viewAboutMeHeading.style.float = "left";
    viewThirdRowDiv.appendChild(viewAboutMeHeading);
    
    let viewAboutMeDiv = document.createElement("div");
        setHeightWidth(viewAboutMeDiv, "150px","calc(100% - 115px)");
        viewAboutMeDiv.style.float = "right";
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
    widthStyle(main, "800px");
    positionRelative(main);
    main.style.margin = "0 auto";
    main.style.marginTop = '200px';
    main.innerHTML = "<button class='actions'>Actions</button><div><table class='data'></table></div>";

    let divMenu = document.createElement('div');
        divMenu.classList.add("menu");

    main.appendChild(divMenu);
    
    let menu = document.querySelector(".menu");
        hide(menu);
        setHeightWidth(menu, "auto", "150px");
        colorBackground(menu, "teal");
        positionAbsolute(menu);
        positionTop(menu, "-14px");
        positionRight(menu);

        let divSubMenu = document.createElement('div');

            let subMenuText = document.createTextNode("Add Student");

            divSubMenu.appendChild(subMenuText);
        
        menu.appendChild(divSubMenu);

            divSubMenu.classList.add("subMenu");
    
        let subMenu = menu.querySelector(".subMenu");
            widthStyle(subMenu, "100%");
            colorStyling(subMenu, "grey", "white");
            subMenu.style.textAlign = "center";
            subMenu.style.padding = "10px 0";

            


let actions = document.querySelector(".actions");
    positionAbsolute(actions);
    positionTop(actions, "-50px");
    positionRight(actions);
    colorStyling(actions, "#5EBA7D", "white");    
    actions.style.border = 'none';
    actions.style.borderRadius = '3px';
    actions.style.padding = '10px 20px';

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
    }

    function cssForm(){
        positionAbsoluteAll(obesiveLayer);
        positionRelative(signupFooter);
        colorBackground(obesiveLayer, "black");        
        setOpacity(obesiveLayer, "0.3");
        hide(modal);
        hide(signupFormSixth);
        hide(signupDelete);
        setInputStyles(signupInputDate,"10px","calc(50% - 85px)","2px 5px");
        setMarginLeft(signupFormThird, "10px"); 
        setFloat(signupInputProgram, "right");
        setMargin(signupFormFourthLabel, "10px");
        setMargin(signupFormTextArea, "10px");
        setPadding(signupFormTextArea, "5px");
        setMargin(signupFormFifthLabel, "10px");
        setMargin(signupFormSixthLabel, "10px");
        setHeight(signupFormSixthInput,"300px");
        setHeightWidth(signupFooter,"50px", "100%");
        setInputStyles(signupInputProgram, "10px", "calc(50% - 20px)", "5px");
        setInputStyles(signupFormFifthInput,"10px","calc(85% - 30px)","5px");
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