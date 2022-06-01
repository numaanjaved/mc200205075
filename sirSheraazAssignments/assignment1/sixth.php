<?php 
echo "Sixth<br>"; 
// Given 2 arrays of ints, a and b, return True if they have the same first element or they have the same last element. Both arrays will be length 1 or more. 

// common_end([1, 2, 3], [7, 3]) → True
// common_end([1, 2, 3], [7, 3, 2]) → False
// common_end([1, 2, 3], [1, 3]) → True
// If count of such matches is more than total number of array elements then copies the element of first array into second and second into first.



function common_end($array1, $array2){
    $boolFirstIndex = false;
    $boolLastIndex = false;
    $bool = false;
    $lengthOfArray1 = count($array1);
    $lengthOfArray2 = count($array2);
    $lastIndexOfArray1 = $lengthOfArray1 - 1;
    $lastIndexOfArray2 = $lengthOfArray2 - 1;
    if($array1[0] == $array2[0]){
        $boolFirstIndex = true;
    }
    if($array1[$lastIndexOfArray1] == $array2[$lastIndexOfArray2]){
        $boolLastIndex = true;
    }
    if($boolFirstIndex || $boolLastIndex){
        $bool = true;
    }
    echo $bool;
}

$array1 = array(1, 2, 3);
$array2 = array(7, 3);

$arrayOne = array(1, 2, 3);
$arrayTwo = array(7, 3, 2);

$array1One = array(1, 2, 3);
$array2Two = array(1, 3);

echo common_end($array1, $array2)."<br>";
echo common_end($arrayOne, $arrayTwo)."<br>";
echo common_end($array1One, $array2Two)."<br>";

exit();