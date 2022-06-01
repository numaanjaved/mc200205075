function borderRoundedDark(input){
    //JQuery with Bootstrap classes rounded, border, border-dark
    $(input).addClass('rounded');
    $(input).addClass('border');
    $(input).addClass('border-dark');
}
function setGrid(input, extraLarge, medium, small, extraSmall){
    //JQuery with Bootstrap classes col-xl-extraLarge, col-md-medium, col-sm-small, col-xs-extraSmall
    $(input).addClass('col-xl-'+extraLarge);
    $(input).addClass('col-md-'+medium);
    $(input).addClass('col-sm-'+small);
    $(input).addClass('col-xs-'+extraSmall);
}

function createRandomString(count){
    let alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    let result = '';
    for(i = 0; i < count; ++i){
        result += alphabets.charAt(Math.floor(Math.random() * alphabets.length));
    }
    return result;
}
function createRandomNumbers(count){
    let result = '';
    for(i = 0; i < count; ++i){
        result += Math.floor(Math.random() * 10);
    }
    return result;
}
function createContainerNumber(number){
    let stringNumber = number.toString();
    let result = '';
    let zerosCount = 2 - stringNumber.length;
    for(let i = 0; i < zerosCount; ++i){
        result += "0";
    }
    result += stringNumber;
    return result;    
}