<?php 
echo "Tenth<br>"; 
//Read numeric values from Text file ( atleast 500 values)  and load the data into binary tree and then traverse it using In-Order Traversal 
class TreeNode{
    public  $left = NULL;
    public $object;
    public $right = NULL;

    public function __construct(){
    }
    public function set($object){
        $this->object = $object;
    }
    public function get(){
        return $this->object;
    }
    public function setLeft($left){
        $this->left = $left;
    }
    public function getLeft(){
        return $this->left;
    }
    public function setRight($right){
        $this->right = $right;
    }
    public function getRight(){
        return $this->right;
    }
}
//To add 500 numbers in a file 
function createIntegerFile($file){
    if(file_exists($file)){
        if(filesize($file) == 0){ 
            for($i = 0; $i < 500; ++$i){
                $number = intval(rand());
                file_put_contents($file, $number."\n", FILE_APPEND);
            }
        }         
    }
}
function readFileToArray($file){
    $numbersArray = file($file);
    return $numbersArray;
}
function insertNode($node, $currentNode){
    if(isset($currentNode->object)){
        if($node->object < $currentNode->object){
            if(!isset($currentNode->left)){
                $leftNode = new TreeNode();
                $leftNode->set($node->object);
                $currentNode->setLeft($leftNode);                
            }
            else{
                insertNode($node, $currentNode->left);
            }
            
        }
        else{
            if(!isset($currentNode->right)){
                $rightNode = new TreeNode();
                $rightNode->set($node->object);
                $currentNode->setRight($rightNode);
            }
            else{
                insertNode($node, $currentNode->right);
            }            
        }
    }
}

function inOrderTraversal($node){
    if(isset($node)){
        inOrderTraversal($node->left);
        echo $node->object." ";
        inOrderTraversal($node->right);
    }
}


$fileName = "numbers.txt";
createIntegerFile($fileName);
$numbersArray = readFileToArray($fileName);

$currentNode = new TreeNode(); 
$currentNode->set($numbersArray[0]);
for($i = 0; $i < 500; ++$i){
    $node = new TreeNode();
    $node->set($numbersArray[$i]);
    insertNode($node, $currentNode);    
} 

inOrderTraversal($currentNode);
exit();