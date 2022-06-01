<?php 
echo "Nineth<br>"; 
//Write a function Alphabet (str) take the str string parameter being passed and return the string with the letters in alphabetical order (ie. hello becomes ehllo).

$string = "glassnode is a good place";
$lengthOfString = strlen($string);
echo "original string = ".$string."<br><br>";

//divide 
//$copyOfString = $string;
//divide($string);

for($i = 0; $i < $lengthOfString; ++$i){
    // echo "First Loop Iteration $i<br>";
    // echo "first loop string alphabet = ".$string[$i]."<br>";
    // echo "ascii of first loop string alphabet = ".ord($string[$i])."<br><br>";
    
    for($j = 0; $j < $lengthOfString; ++$j){
        // echo "Second Loop Iteration $j<br>";
        // echo "second loop string alphabet = ".$string[$j]."<br>";
        // echo "ascii of second loop string alphabet = ".ord($string[$j])."<br><br>";

        if(ord($string[$i]) < ord($string[$j])){
            // echo "first Loop alphabet is alphabetically lower than second loop alphabet<br><br>";
            $temp = $string[$i];
            $string[$i] = $string[$j];
            $string[$j] = $temp;
        }
    }
    
}
echo "<br>updated string = ".$string."<br><br>";
exit();