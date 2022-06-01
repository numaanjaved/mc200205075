// console.log(document.currentScript.src);
function setInputAttributes(input, type, name, placeholder){
    input.setAttribute("type",type);
    input.setAttribute("name",name);
    input.setAttribute("placeholder", placeholder);
}
function setInputStyles(input, margin, width, padding){
    //input, margin, width, padding
    input.style.margin = margin;
    input.style.setProperty("width", width);
    input.style.padding = padding;
}

function toggleMenu(clicked, target){
    let countClick = 0;
    clicked.addEventListener("click", function(event){    
        if(countClick%2 == 1){
            hide(target);
        }
        else{
            displayBlock(target);
        }
        ++countClick;
    });
}
function hide(input){
    input.style.display = "none";
}
function displayBlock(input){
    input.style.display = "block";
}
function colorBackground(input, color){
    input.style.backgroundColor = color;
}
function colorFont(input, color){
    input.style.color = color;
}
function colorStyling(input, colorBackGround, colorfont){
    colorBackground(input, colorBackGround);
    colorFont(input, colorfont);
}
function positionAbsolute(input){
    input.style.position = "absolute";
}
function positionRelative(input){
    input.style.position = "relative";
}
function positionTop(input, top = 0){
    input.style.top = top;
}
function positionLeft(input, left = 0){
    input.style.left = left;
}
function positionBottom(input, bottom = 0){
    input.style.bottom = bottom;
}
function positionRight(input, right = 0){
    input.style.right = right;
}
function positionTopBottom(input, top = 0, bottom = 0){
    positionTop(input, top);
    positionBottom(input, bottom);
}
function positionLeftRight(input, left = 0, right = 0){
    positionLeft(input, left);
    positionRight(input, right);
}
function positionAbsoluteHorizontal(input, left = 0, right = 0){
    positionAbsolute(input);
    positionLeftRight(input, left, right);
}
function positionAbsoluteVertical(input, top = 0, bottom = 0){
    positionAbsolute(input);
    positionTopBottom(input, top, bottom);
}
function positionAbsoluteAll(input, top = 0, left = 0, right = 0, bottom = 0){
    positionAbsolute(input);
    positionTopBottom(input, top, bottom);
    positionLeftRight(input, left, right);
}
function widthStyle(input, width){
    if(width.includes("calc")){
        input.style.setProperty("width", width);
    }else{
        input.style.width = width;
    }
    
}
function setHeight(input, height){
    if(height.includes("calc")){
        input.style.setProperty("height", height);
    }else{
        input.style.height = height;
    }
}
function setHeightWidth(input, height, width){
    setHeight(input, height);
    widthStyle(input, width);
}
function setFooter(input,left, right){
    widthStyle(input, "30%");
    colorStyling(input, "#5EBA7D", "white");
    positionAbsoluteAll(input, "0", left, right,"0");
    input.style.border = "none";
    input.style.borderRadius = "20px";
}
function createModalInnerDiv(inputContainer, input){
    setHeightWidth(inputContainer,"550px", "490px");
    inputContainer.style.overflowY = "auto";
    inputContainer.style.overflowX = "hidden";
    positionAbsoluteAll(inputContainer, "50%", "50%");
    inputContainer.style.transform = "translateX(-50%) translateY(-50%)";
    
        setHeightWidth(input,"auto","460px");
        colorBackground(input, "white");
        input.style.border = "none";
        input.style.borderRadius = "10px";
        input.style.padding = "10px";
    inputContainer.appendChild(input);
}
function createModalInnerDivHeader(input, inputHeader, inputHeading, inputClose){
    setHeightWidth(inputHeader,"50px", "100%");
    inputHeader.style.float = "left";
    inputHeader.style.fontFamily = "Arial";
    inputHeader.style.fontSize = "40px";
    
    inputClose.style.float = "right";
    inputClose.classList.add('fa');
    inputClose.classList.add('fa-times');

    inputHeader.appendChild(inputHeading);
    inputHeader.appendChild(inputClose);
    input.appendChild(inputHeader);
}
function createModalDivider(input){
    let inputDivider = document.createElement('hr');
    input.appendChild(inputDivider);
}
function createModalMain(input, inputMain){ 
    widthStyle(inputMain, "100%");
    inputMain.style.setProperty( "height","calc(100% - 130px)");
    input.appendChild(inputMain);
}
function createName(input, inputName, text = "", textPlaceHolder = ""){
    //Enter one space in text and textPlaceHolder
    setInputAttributes(inputName,"text", `${text}-name`,`Enter Your ${textPlaceHolder} Name`);
    setInputStyles(inputName,"10px","calc(50% - 35px)","5px");
    if(text.includes('first')){
        inputName.style.float = "left";   
    }
    else{
        inputName.style.float = "right";   
    }
    input.appendChild(inputName);
}
function createFormName(input, text = "", textPlaceHolder = ""){
    let inputFormName = document.createElement('div');
                    
        let inputFirstName = document.createElement('input');
        createName(inputFormName, inputFirstName, `${text}first`, `${textPlaceHolder}First`);

        let inputLastName = document.createElement('input');
        createName(inputFormName, inputLastName, `${text}last`, `${textPlaceHolder}Last`);    

    input.appendChild(inputFormName);       
}
function removeSignupContainer(input){
    if(input.querySelector("#signup-container")){
        input.removeChild(signupContainer);
    } 
}
function removeViewContainer(input){
    if(input.querySelector("#view-container")){
        input.removeChild(viewContainer);
    } 
}
function removeAllContainers(input){
    removeSignupContainer(input);
    removeViewContainer(input);
}
function replaceContainerforView(input){    
    removeAllContainers(input);
    input.appendChild(viewContainer);
}
function replaceContainerforNotView(input){
    removeAllContainers(input);
    input.appendChild(signupContainer);
}
function setID(input, id){
    input.id = id;
}
function setMargin(input, margin){
    input.style.margin = margin;
}
function setMarginLeft(input, marginLeft){
    input.style.marginLeft = marginLeft;
}
function setOpacity(input, opacity){
    input.style.opacity = opacity;
}
function setFloat(input, float){
    input.style.float = float;
}
function setPadding(input, padding){
    input.style.padding = padding;
}
function setName(input, name){
    input.setAttribute("name", name);
}
function setRows(input, rows){
    input.rows = rows;
}
function setCols(input, cols){
    input.cols = cols;
}
function setRowsCols(input, rows, cols){
    setRows(input, rows);
    setCols(input, cols);
}
function setType(input, type){
    input.type = type;
}
function setValue(input, value){
    input.value = value;
}
function hideAllDivs(form){
    formDivs = form.querySelectorAll("div");
    for(let i = 0; i < formDivs.length; ++i){
        hide(formDivs[i]);
    }
}
function hideDoubleDiv(form, name1, name2){
    formDivs = form.querySelectorAll("div");
    for(let i = 0; i < formDivs.length; ++i){
        if(formDivs[i].id.includes(name1) || formDivs[i].id.includes(name2)){
            hide(formDivs[i]);
        }else{
            displayBlock(formDivs[i]);
        }                                
    }
}
function showOnlyDiv(form, name){
    formDivs = form.querySelectorAll("div");
    for(let i = 0; i < formDivs.length; ++i){
        if(formDivs[i].id.includes(name)){
            displayBlock(formDivs[i]);
        }else{
            hide(formDivs[i]);
        }                                
    }
}
