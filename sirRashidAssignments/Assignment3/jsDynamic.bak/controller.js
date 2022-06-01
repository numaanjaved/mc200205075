function validation(entry){
    let valid;
    if(entry.value == ""){
        entry.style.borderColor = "red";
        valid = false;
    }
    else{
        entry.style.borderColor = "inherit";
        valid = true;
    }
    return valid;
}
function validated(data){
    countValidated = 0;
    boolValidated = false;    
    for(let i = 0; i < data.length; ++i){        
        if(data[i].name == "first-name"){
            validation(data[i]);
        }
        if(data[i].name == "last-name"){
            validation(data[i]);
        }
        if(data[i].name == "father-first-name"){
            validation(data[i]);
        }
        if(data[i].name == "father-last-name"){
            validation(data[i]);
        }
        if(data[i].name == "date"){
            validation(data[i]);
        }
        if(data[i].name == "program"){
            validation(data[i]);
        }
        if(data[i].name == "aboutMe"){
            validation(data[i]);
        }
        if(data[i].name == "image"){
            validation(data[i]);
        }
        if(validation(data[i])){
            ++countValidated;
        }
    }
    if(countValidated == data.length){
        boolValidated = true;
    }
    return boolValidated;
}

var studentArray = [];
submitFormInput.addEventListener("click", function(event){
    event.preventDefault();
    let data = form.elements;
    if(validated(data) == true){        
        var student = new Student;
        countAssigned = 0;
        for(let i = 0; i < data.length; ++i){        
            if(data[i].name == "first-name"){
                student.name.firstName = data[i].value;
            }
            if(data[i].name == "last-name"){
                student.name.lastName = data[i].value;
            }
            if(data[i].name == "father-first-name"){
                student.father.firstName = data[i].value;
            }
            if(data[i].name == "father-last-name"){
                student.father.lastName = data[i].value;
            }
            if(data[i].name == "date"){
                student.setStartDate(data[i].value);
            }
            if(data[i].name == "program"){
                student.setProgram(data[i].value);
            }
            if(data[i].name == "aboutMe"){
                student.setAboutMe(data[i].value);
            }
            if(data[i].name == "image"){
                student.setImage(data[i].files[0]);
            }
            if(validation(data[i])){
                ++countAssigned;                
            }
        }
        if(countAssigned == data.length){
            if(form.id.includes("add") == true){              
                student.setVUID();
                studentArray.push(student);
                let studentReadArray = [];
                studentReadArray.push(student.getVUID());
                studentReadArray.push(student.getImage());
                studentReadArray.push(student.getName());
                studentReadArray.push(student.getProgram());        
                hide(modal);
                formReset();
                createRow(studentReadArray);  
            }
            else if(form.id.includes("update")){
                let parts = form.id.split("-", 4);
                RollNo = parts[3];
                for(let i = 0; i < studentArray.length; ++i){
                    let rollNo = studentArray[i].getVUID().wholeText;
                    if(rollNo == RollNo){                        
                        boolProgram = student.getProgramValue() == studentArray[i].getProgramValue();
                        if(boolProgram == true){
                            student.setSpecificVUID(rollNo);
                        }
                        else{
                            student.setVUID();
                        }
                        studentArray[i] = student;
                        let studentUpdateArray = [];
                        studentUpdateArray.push(student.getVUID());
                        studentUpdateArray.push(student.getImage());
                        studentUpdateArray.push(student.getName());
                        studentUpdateArray.push(student.getProgram());
                        hide(modal);
                        formReset();
                        updateRow(studentUpdateArray);
                        student.destroy();
                    }                    
                }
                    
            }            
        }       
    }
    if(form.id.includes("delete")){
        let parts = form.id.split("-", 4);
        RollNo = parts[3]; let boolDelete = false; let tempRollNo = 0; let index;
        for(let i = 0; i < studentArray.length; ++i){
            let rollNo = studentArray[i].getVUID().wholeText;
            if(rollNo == RollNo){   
                boolDelete = true;
                tempRollNo = rollNo;
                index = i;
                break;             
            }   
        }
        if(boolDelete == true){
            deleteRow(tempRollNo);
            delete studentArray[index];
            hide(modal);
            formReset();            
        }
    }
});
function selectStudent(RollNo){
    let studentSelected; let boolID = false;
    for(let i = 0; i < studentArray.length; ++i){
        
        if(studentArray[i] !== undefined){
            let VUID = studentArray[i].getVUID().wholeText;
            boolID = VUID == RollNo;
            if(boolID == true){
                studentSelected = studentArray[i];
                break;
            }
        }
        
    }
    return studentSelected;
}
function settingValuesInView(RollNo){
    console.log(RollNo);
    let studentSelected = selectStudent(RollNo);
    let viewArray = [
        image = studentSelected.getImage(),
        vuid = studentSelected.getVUID().wholeText,
        gname = studentSelected.getName().wholeText,
        fatherName = studentSelected.getFatherName().wholeText,
        semester = studentSelected.getSemester(),
        program = studentSelected.getProgram().wholeText,
        aboutme = studentSelected.getAboutMe()
    ];//no for loop
    if(viewArray[0]){
        viewImageDiv.appendChild(viewArray[0]);
    }
    if(viewArray[1]){
        viewMainRollNoDiv.innerHTML = "VUID : "+ viewArray[1];
    }
    if(viewArray[2]){
        viewMainNameDiv.innerHTML = "Name : "+ viewArray[2];
    }
    if(viewArray[3]){
        viewFatherNameDiv.innerHTML = "Father's Name : "+ viewArray[3];
    }
    if(viewArray[4]){
        viewSemester.innerHTML = "Semester : "+ viewArray[4];
    }
    if(viewArray[5]){
        viewProgram.innerHTML = "Program : "+ viewArray[5];
    }
    if(viewArray[6]){
        viewAboutMeHeading.innerHTML = "About Me : ";
        viewAboutMeDiv.innerHTML = aboutme;
    }    
}
function settingValuesInUpdate(RollNo){
    let studentSelected = selectStudent(RollNo);
    for(let i = 0; i < inputs.length; ++i){        
        if(inputs[i].name == "first-name"){
            inputs[i].value = studentSelected.name.firstName;
        }
        if(inputs[i].name == "last-name"){
            inputs[i].value = studentSelected.name.lastName;
        }
        if(inputs[i].name == "father-first-name"){
            inputs[i].value = studentSelected.father.firstName;
        }
        if(inputs[i].name == "father-last-name"){
            inputs[i].value = studentSelected.father.lastName;;
        }
        if(inputs[i].name == "date"){            
            inputs[i].value = studentSelected.getStartDate();
        }
        if(inputs[i].name == "program"){
            inputs[i].value = studentSelected.getProgramValue();
        }
        if(inputs[i].name == "aboutMe"){
            inputs[i].value = studentSelected.getAboutMe();
        }
        if(inputs[i].name == "image"){
            let image = document.querySelector("#form-image");
            image.src = studentSelected.getImageSrc();
            let parent = image.parentElement;
            displayBlock(parent);                                
        }
    }
}
