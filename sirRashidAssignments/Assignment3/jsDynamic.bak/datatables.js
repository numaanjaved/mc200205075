let data = document.querySelector('.data'); 
    setHeightWidth(data, "auto", "800px");
    setMargin(data, "0 auto");
    data.style.backgroundColor = "white";
    
    data.style.borderRadius = '20px';
    data.innerHTML = "<thead></thead><tbody></tbody>";
    data.parentElement.style.height = "400px";
    data.parentElement.style.width = "850px";
    data.parentElement.style.overflowY = "auto";
    let tableHead = data.querySelector("thead");
    let tableBody = data.querySelector("tbody");
    let headingRow = document.createElement('tr');
// let headingColumn = document.createElement('th');
let headingText = ['RollNo', 'Image', 'Name','Program', 'Action'];
for(let i = 0; i < headingText.length; ++i){
    let headingColumn = document.createElement('th');
    if(headingText[i] == "Action"){
        headingColumn.style.width = "50px";
    }
    else{
        headingColumn.style.width = "100px";
    }
    
    headingColumn.style.height = "100px";
    
    headingColumn.style.border = "inherit";
   
    let textInHeader = document.createTextNode(headingText[i]);
    tableHead.appendChild(headingRow).appendChild(headingColumn).appendChild(textInHeader);
}




function subMenuInActionRow(student){    
    let button = document.createElement('span');
        button.style.border = "1px solid black";
        button.style.backgroundColor = "grey";
        let RollNo = student;
        button.id = "actionsInsideRow-"+RollNo;
        let actionButtonInside =  "<i class='fas fa-bars'></i>"; 
        button.innerHTML = actionButtonInside;
        let MenuInActionButton =  document.createElement("div");
            MenuInActionButton.id = "menu-action-"+student;
            hide(MenuInActionButton);
            MenuInActionButton.style.width = "160px";
            MenuInActionButton.style.height = "auto";
            positionAbsolute(MenuInActionButton);
            MenuInActionButton.style.right = "36px";
            MenuInActionButton.style.backgroundColor = "transparent";
            
            for(let i = 0; i < 3; ++i){
                let menuChild = document.createElement('div');
                if(i == 1){
                    menuChild.innerText = "Update";
                    menuChild.id = "update-";
                }
                else if(i == 2){
                    menuChild.innerText = "Delete";
                    menuChild.id = "delete-"
                }
                else{
                    menuChild.innerText = "View";
                    menuChild.id = "view-";
                    
                }
                menuChild.id += RollNo;
                menuChild.style.padding = "10px 0";
                menuChild.style.height = "20px";
                menuChild.style.width = "100%";
                menuChild.style.color = "teal";
                menuChild.style.backgroundColor = "white";
                menuChild.style.border = "1px solid blue";
                menuChild.style.borderRadius = "10px";
                menuChild.style.textAlign = "center";

                menuChild.addEventListener("click", function(){
                    if(menuChild.id.includes("view")){
                        // view functionality
                        pageView(RollNo);                        
                    }
                    if(menuChild.id.includes("update")){
                        // update functionality
                        pageUpdate(RollNo)
                    }
                    if(menuChild.id.includes("delete")){
                        // delete Functionality
                        pageDelete(RollNo);
                    }
                    hide(MenuInActionButton);
                    displayBlock(modal);
                });
                MenuInActionButton.appendChild(menuChild);
            }
                
        button.appendChild(MenuInActionButton);
        let actionB = button.querySelector("i");
        toggleMenu(actionB, MenuInActionButton);
    return button;
}

function createRow(student){
    
    let bodyRow = document.createElement('tr');
    bodyRow.style.height = '100px';
    bodyRow.style.border = '1px solid black';
    bodyRow.style.backgroundColor = 'white';
    bodyRow.style.textAlign = "center";
    let rowInBody = tableBody.appendChild(bodyRow);

    for(let j = 0; j < headingText.length; ++j){
        let bodyColumn = document.createElement('td');
        // bodyColumn.style.backgroundColor = '#5EBA7D';
        bodyColumn.style.border = "1px solid black";
        bodyColumn.style.borderRadius = '20px';
        let textInBody;
        if(j == 4){
            textInBody = subMenuInActionRow(student[0].wholeText);
        }
        else{
            textInBody = student[j];
        }
        rowInBody.appendChild(bodyColumn).appendChild(textInBody);
    }
}
function updateRow(student){
    let rollNo = student[0].wholeText;
    let rows = data.querySelectorAll("tbody > tr");
    for(let i = 0; i < rows.length; ++i){
        let columns = rows[i].querySelectorAll("td");
        columnRowRollNo = columns[0].textContent;
        if(columnRowRollNo == rollNo){
            for(let j = 1; j < columns.length - 1; ++j){
                columns[j].innerHTML = "";
                columns[j].appendChild(student[j]);
            }
        }
    }
}

function deleteRow(rollNo){
    let boolDelete = false; let number = 0;
    let tbody = data.querySelector('tbody');
    let rows = tbody.querySelectorAll("tr");
    for(let i = 0; i < rows.length; ++i){
        let columns = rows[i].querySelectorAll("td");
        columnRowRollNo = columns[0].textContent;
        if(columnRowRollNo == rollNo){
            
            boolDelete = true;
            number = i;
            break;
        }       
    }
    if(boolDelete == true){
        tbody.deleteRow(number);
    }
}
