<?php 
echo "Fifth<br>"; 
//Given an array of ints, return true if 1, 2, 3 all appears in the array somewhere
//array123([1,1,2,3,1] -> TRUE
//array123([1,1,2,4,1] -> FALSE
//array123([1,1,2,1,2,3]) -> TRUE

function array123($numbers){
    $boolUltimate = false;
    $one = 1; $boolOne = false;
    $two = 2; $boolTwo = false;
    $three = 3; $boolThree = false;
    $lengthOfArray = count($numbers);
    $bool = false;
    for($i = 0; $i < $lengthOfArray; ++$i){
        if($numbers[$i] == $one){
            $boolOne = true;
        }
        if($numbers[$i] != $one  && $numbers[$i] == $two){
            $boolTwo = true;
        }
        if($numbers[$i] == $three){
            $boolThree = true;
        }
    }
    if($boolOne && $boolTwo && $boolThree){
        $boolUltimate = true;
    }
    return $boolUltimate;
}
$numbers = array(
    1, 1, 2, 3, 1
);
$numbers1 = array(
    1, 1, 2, 4, 1
);
$numbers2 = array(
    1, 1, 2, 1, 2, 3
);
echo array123($numbers)."<br>";
echo array123($numbers1)."<br>";
echo array123($numbers2)."<br>";
exit();