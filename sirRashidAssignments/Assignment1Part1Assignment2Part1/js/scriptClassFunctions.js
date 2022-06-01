function addClass(input, cssClass){
    input.classList.add(cssClass);
}
function addDoubleClass(input, cssClass1, cssClass2){
    input.classList.add(cssClass1, cssClass2);
}
function removeClass(input, cssClass){
    input.classList.remove(cssClass);
}
function removeDoubleClass(input, cssClass1, cssClass2){
    input.classList.remove(cssClass1, cssClass2);
}
function invalidateBorder(input){
    addClass(input,"borderColor-validation");
}
function invalidateBorderAll(input){
    for(let i = 0; i < input.length; ++i){
        invalidateBorder(input[i]);
    }                    
}
function validateBorderAll(input){
    for(let i = 0; i < input.length; ++i){
        validateBorder(input[i]);
    }                    
}
function validateBorder(input){
    removeClass(input,"borderColor-validation");
}
function validateIcon(input){
    removeDoubleClass(input, "fa", "fa-exclamation-circle");
}
function invalidateIcon(input){
    addDoubleClass(input, "fa", "fa-exclamation-circle");
}
function displayToolTip(input){
    removeClass(input, "d-none");
    addClass(input, "d-inline-block");
}
function hideToolTip(input){
    removeClass(input, "d-inline-block");
    addClass(input, "d-none");
}
function hideAllToolTips(input){
    for(let i = 0; i < input.length; ++i){
        hideToolTip(input[i]);
    }

}