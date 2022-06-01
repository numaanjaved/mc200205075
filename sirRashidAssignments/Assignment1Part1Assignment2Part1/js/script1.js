
let buttonSignup = document.querySelector(".signupButton");
function checkerFirstCondition(entry){
    let firstnameCondition = entry.name == "first-name";
    let inputFirstName = form.querySelector("input[name='first-name']");
    let positionIconFirstName = inputFirstName.nextElementSibling;
    if(firstnameCondition){
        if(entry.value == ""){
            invalidateBorder(inputFirstName);
            invalidateIcon(positionIconFirstName);
        }
        else{
            validateBorder(inputFirstName);
            validateIcon(positionIconFirstName);
        }                
    }
}
function actionMouseOverMouseOut(formEntry, positionIcon, tooltips, positionToolTip){
    formEntry.addEventListener("mouseover", function(event){
        if(formEntry.value == ""){
            validateBorder(formEntry);
            validateIcon(positionIcon);   
            hideAllToolTips(tooltips);                     
            displayToolTip(positionToolTip);
        }
    });
    formEntry.addEventListener("mouseout", function(event){
        if(formEntry.value == ""){
            invalidateBorder(formEntry);
            invalidateIcon(positionIcon);
            hideToolTip(positionToolTip);
        }
    });
}
function fieldsExceptRadioAction(formEntry, tooltips, profile){
    // console.log(formEntry.name);
    if(formEntry.classList.contains("type-1")){
        var positionIcon = formEntry.nextElementSibling;
        var positionToolTip = document.querySelector(`.contextual #tool-${formEntry.name}`);
    }
    if(formEntry.classList.contains("type-2")){
        var positionIcon = form.querySelector("#part2").previousElementSibling;
        var positionToolTip = document.querySelector(".contextual #tool-dateOfBirth");
    }
    if(formEntry.classList.contains("type-3")){
        var positionIcon = form.querySelector("#part3").previousElementSibling;
    }
    if(formEntry.value == ""){
        invalidateBorder(formEntry);
        invalidateIcon(positionIcon);
        actionMouseOverMouseOut(formEntry, positionIcon, tooltips, positionToolTip);
    }
    else{   
        if(positionIcon && !!formEntry.classList.contains("type-3")){
            validateIcon(positionIcon);
        }
        if(positionToolTip){
            hideToolTip(positionToolTip);      
        }            
        validateBorder(formEntry);
        if(formEntry.name == "first-name"){
            profile.setFirstName(formEntry.value);
        }
        if(formEntry.name == "sur-name"){
            profile.setSurName(formEntry.value);
        }
        if(formEntry.name == "username"){
            profile.setUserName(formEntry.value);
        }
        if(formEntry.name == "password"){
            profile.setPassword(formEntry.value);
        }
        if(formEntry.name == "day"){
            profile.dateOfBirth.setDay(formEntry.value);
        }
        if(formEntry.name == "month"){
            profile.dateOfBirth.setMonth(formEntry.value);
        }
        if(formEntry.name == "year"){
            profile.dateOfBirth.setYear(formEntry.value);
        }
    }       
}
class DateOfBirth{
    day;
    month;
    year;
    setDay(day){
        this.day= day;
    }
    setMonth(month){
        this.month = month;
    }
    setYear(year){
        this.year = year;
    }
    getDay(){
        return this.day;
    }
    getMonth(){
        return this.month;
    }
    getYear(){
        return this.year;
    }
    get(){
        return this.day + "." + this.month + "." + this.year;
    }
}
class Profile{
    firstName;
    surName;
    userName;
    #password;
    dateOfBirth = new DateOfBirth();
    gender;
    status;
    setFirstName(firstName){
        this.firstName = firstName.toString();
    }
    setSurName(surName){
        this.surName = surName;
    }
    setUserName(userName){
        this.userName = userName;
    }
    setPassword(password){
        this.password = password;
    }
    setDateOfBirth(dateOfBirth){
        this.dateOfBirth = dateOfBirth;
    }
    setGender(gender){
        this.gender = gender;
    }
    activate(){
        this.status = true;
    }
    deActivate(){
        this.status = false;
    }
    getFirstName(){
        return this.firstName;
    }
    getSurName(){
        return this.surName;
    }
    getUserName(){
        return this.userName;
    }
    getPassword(){
        return this.password;
    }
    getDateOfBirth(){
        return this.dateOfBirth;
    }
    getGender(){
        return this.gender;
    }
    getStatus(){
        return this.status;
    }
    get(){
        return this;
    }
}


buttonSignup.addEventListener("click", function(){
    var modal = document.querySelector(".modal");
    var form = modal.querySelector("#form");
    var tooltips = form.querySelectorAll(".tooltip");
    let success = document.querySelector(".success");

    //console.log(tooltips);

    let inputRadio = form.querySelectorAll("#part3 span");
    var formEntries = form.elements;

    form.reset();
    //modal.classList.remove("d-none");
    removeClass(modal, "d-none");
    //modal.classList.add("d-block");
    addClass(modal, "d-block");    
    hideAllToolTips(tooltips);
    let signUpFormSubmit = modal.querySelector("input[type='submit']");
    signUpFormSubmit.addEventListener("click", function(event){
        event.preventDefault();
        let boolAllFilled = false;
        let countAllFilled = 0;
        hideAllToolTips(tooltips);
        let selectConditionTest = false;
        var positionIconRadio = form.querySelector("#part3").previousElementSibling;
        console.log(positionIconRadio);
        //condition for Radio option
        let radioCondition = true;
       
        var profile = new Profile();
        for(let i = 0; i < formEntries.length; ++i){
            let radioConditionTrue = formEntries[i].name == "sex" && formEntries[i].checked == true;

            fieldsExceptRadioAction(formEntries[i], tooltips, profile);
            
            if(radioConditionTrue){
                radioCondition = false;
                profile.setGender(formEntries[i].value);
            }
        }
        if(radioCondition == false){
            for(let i = 0; i < inputRadio.length; ++i){
                validateBorder(inputRadio[i]);
                validateIcon(positionIconRadio);
            }
        }
        else{
            for(let i = 0; i < inputRadio.length; ++i){
                invalidateBorder(inputRadio[i]);
                invalidateIcon(positionIconRadio);
            }
        }
        for(let i in profile){
            let student = profile[i];
            if(profile[i] !== undefined){
                // console.log(i);
                if(typeof profile[i] !== "object"){
                    ++countAllFilled;
                }
                else{
                    countDOB = 0;
                    for(j in profile[i]){
                        if(profile[i][j] !== undefined)
                        ++countDOB;
                    }
                    if(countDOB == 3){
                        selectConditionTest = true;
                        console.log(selectConditionTest);
                        ++countAllFilled;
                    }
                }
            }
        }
        if(countAllFilled == 6){
            boolAllFilled = true;
            hideAllToolTips(tooltips);
            profile.activate();
        }
        if(profile.getStatus() == true){
            console.log(profile);
            success.innerHTML = "Congratulations " + profile.getFirstName() + "! Your account is hacked. Your Password is "+ profile.getPassword();
            addClass(form, "d-none");
            removeClass(success, "d-none");
            addClass(success, "d-block");
        }
        
    });
    for(let i = 0; i < formEntries.length; ++i){
        formEntries[i].addEventListener("blur", function(){
            checkerFirstCondition(formEntries[0]);
            if(formEntries[i].classList.contains("type-1")){
                var positionIcon = formEntries[i].nextElementSibling;
                var positionToolTip = document.querySelector(`.contextual #tool-`+formEntries[i].name);
            }
            if(formEntries[i].classList.contains("type-2")){
                var positionIcon = form.querySelector("#part2").previousElementSibling;
                var positionToolTip = document.querySelector(".contextual #tool-dateOfBirth");
            }
            if(formEntries[i].parentElement.classList.contains("type-3")){
                var positionIcon = form.querySelector("#part3").previousElementSibling;   
                var positionBorder = form.querySelectorAll(".type-3");     
            }
            if(positionIcon){
                validateIcon(positionIcon);                
            }
            if(positionToolTip){
                hideToolTip(positionToolTip);
            }
            if(formEntries[i].value == "" || (formEntries[i].type == 'radio' && formEntries[i].checked == false)){
                if(positionBorder){
                    invalidateBorderAll(positionBorder);             
                }               
                if(positionIcon){
                    invalidateIcon(positionIcon);
                }
                invalidateBorder(formEntries[i]);
            }
            else{
                if(positionBorder){
                    validateBorderAll(positionBorder);             
                }    
                validateBorder(formEntries[i]);
            }
            
                
            
        });
        formEntries[i].addEventListener("focus", function(){
            validateBorder(formEntries[i]);
            if(formEntries[i].classList.contains("type-1")){
                var positionToolTip = document.querySelector(`.contextual #tool-`+formEntries[i].name);
            }
            if(formEntries[i].classList.contains("type-2")){
                var positionToolTip = document.querySelector(".contextual #tool-dateOfBirth");
            }
            if(positionToolTip){
                displayToolTip(positionToolTip);
            }
        });
    }
    signUpFormSubmit.addEventListener("mousedown", function(event){
        let form = modal.querySelector("#form");
        
        let formEntries = form.elements;
        
        for(let i = 0; i < formEntries.length; ++i){
            checkerFirstCondition(formEntries[i]);
        }
    });
    let close = modal.querySelector(".close");
    close.addEventListener("click", function(event){
        let form = modal.querySelector("#form");
        modal.classList.remove("d-block");
        modal.classList.add("d-none");
        removeClass(success, "d-block");
        addClass(success, "d-none");
        removeClass(form, "d-none");
        addClass(form, "d-block");
        form.reset();
    });
});