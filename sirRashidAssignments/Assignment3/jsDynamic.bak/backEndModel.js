// console.log(this.src);
class Name{
    firstName;
    lastName;

    setFirstName(firstName){
        this.firstName = firstName;
    }
    setLastName(lastName){
        this.lastName = lastName;
    }
    getFirstName(){
        return this.firstName;
    }
    getLastName(){
        return this.lastName;
    }
    get(){
        return this.firstName + " " + this.lastName;
    }
}
class Program{
    name;
    code;

    setName(value){
        if(value == 1){
            this.name = "Bachelors";
        }
        if(value == 2){
            this.name = "Masters";
        }
    }
    setCode(value){
        if(value == 1){
            this.code = "bc";
        }
        if(value == 2){
            this.code = "mc";
        }
    }
    set(name){
        this.setName(name);
        this.setCode(name);
    }
    get(){
        return this.name;
    }
}
class EnrollmentDate{
    day;
    month;
    year;
    code = "";

    setDay(day){
        this.day = day;
    }
    setMonth(month){
        this.month = month;
    }
    setYear(year){
        this.year = year;
    }
    setCode(){
        if(this.day && this.month && this.year){
            for(let i = 0; i < this.year.length; ++i){
                if(i > 1){
                    this.code += this.year[i];
                }
            }
            if(this.month < 6){
                this.code += "02";
            }
            else{
                this.code += "04";
            }
        }
    }
    set(date){
        const splittedDate = date.split("-",3);
        this.setDay(splittedDate[2]);
        this.setMonth(splittedDate[1]);
        this.setYear(splittedDate[0]);
        this.setCode();
    }
    get(){
        return this.year+"-"+this.month+"-"+this.day;
    }

}
class UniversityDetail{
    program = new Program;
    startDate = new EnrollmentDate;
    semester;
    vuid = ""; 

    setProgram(program){
        this.program.set(program);
    }
    setStartDate(date){
        this.startDate.set(date);
        this.setSemester();
    }
    setSemester(){
        if(this.startDate.month < 6){
            this.semester = "Spring";
        }
        else{
            this.semester = "Fall";
        }
    }
    getSemester(){
        return this.semester;
    }
    getStartDate(){
        return this.startDate.get();
    }
    setVUID(){
        if(this.program.code && this.startDate.code){
            this.vuid = this.program.code + this.startDate.code;
        }
        let countRead = Student.count.toString();
        let zerosCount = 5 - countRead.length;

        for(let i = 0; i < zerosCount; ++i){
            this.vuid += "0";
        }
        this.vuid += countRead;
    }
    setSpecificVUID(number){
        this.vuid = number;
    }
    getVUID(){
        return this.vuid;
    }
}
class Student{
    number = 0;
    static count;
    name = new Name;
    father = new Name;
    universityDetail = new UniversityDetail;
    aboutMe = "";
    image = "";

    constructor(){
        ++Student.count;
        this.number = Student.count;
    }
    setName(firstName, lastName){
        this.name.setFirstName(firstName);
        this.name.setLastName(lastName);
    }
    getName(){
        let name = this.name.firstName + " " + this.name.lastName;
        let Name = document.createTextNode(name);
        return Name;
    }
    setFatherName(fatherFirstName, fatherLastName){
        this.father.setFirstName(fatherFirstName);
        this.father.setLastName(fatherLastName);
    }
    getFatherName(){
        let fathername = this.father.firstName + " " + this.father.lastName;
        let fatherName = document.createTextNode(fathername);
        return fatherName;
    }
    setStartDate(date){
        this.universityDetail.setStartDate(date);
    }
    getStartDate(){
        return this.universityDetail.getStartDate();
    }
    setProgram(program){
        this.universityDetail.setProgram(program);
    }
    getProgram(){
        let program = document.createTextNode(this.universityDetail.program.name);
        return program;
    }
    getProgramValue(){
        let value; 
        if(this.getProgram().wholeText == "Bachelors"){
            value = 1;
        }
        else if(this.getProgram().wholeText == "Masters"){
            value = 2;
        }
        return value;
    }
    setAboutMe(aboutMe){
        this.aboutMe = aboutMe;
    }
    getAboutMe(){
        return this.aboutMe;
    }
    setImage(image){
        let Image = URL.createObjectURL(image);
        this.image = Image;
    }
    getImageSrc(){
        return this.image;
    }
    getImageFile(){
        let file = new File([this.getImageSrc()], "file.jpeg");
        return file.name;
    }
    getImage(){
        let img = document.createElement('img');
            img.setAttribute("src", this.image);
            img.style.height = "60%";
            img.style.width = "80%";
        return img;
    }
    getSemester(){
        return this.universityDetail.getSemester();
    }
    setVUID(){
        this.universityDetail.setVUID();
    }
    setSpecificVUID(number){
        this.universityDetail.setSpecificVUID(number);
    }
    getVUID(){
        let vuid = document.createTextNode(this.universityDetail.getVUID().toString());
        return vuid;
    }
    destroy(){
        Student.count--;
        delete this;
    }
}
Student.count = 0;