<?php 
echo "Fourth<br>"; 
//Given a string and a non negative int a, return a larger string that is n copies of the original string.

function copiesOfString($string, $number){
    $result = NULL;
    for($i = 0; $i < $number; ++$i){
        $result .= $string;
    }
    return $result;
}
$strings = "University";

$numbers = 6;
$result = copiesOfString($strings, $numbers);
echo $result;
exit();