<?php 
echo "Third<br>"; 
//Write a program to return the third and last largets number in the array if first largest number is greater than  largest by 20%

$numbersArray = array(
    5, 4, 100, 81, 10, 70
);
function calculationThird($numbersArray){
    $lengthOfArray = count($numbersArray);
    $largest['first'] = $numbersArray[0]; 
    $largest['second'] = $numbersArray[0];
    $largest['third'] = $numbersArray[0];
    for($i = 0; $i < $lengthOfArray; ++$i){
        // echo "First Largest = ".$largest['first']."<br>";
        // echo "Second Largest = ".$largest['second']."<br>";
        // echo "Third Largest = ".$largest['third']."<br>";
        // echo "i = ".$i."<br>";
        // echo "number = ".$numbersArray[$i]."<br>";
        if($largest['first'] < $numbersArray[$i]){
            $largest['first'] = $numbersArray[$i];
        }   
        if($largest['first'] != $numbersArray[$i] && $largest['second'] < $numbersArray[$i]){
            $largest['second'] = $numbersArray[$i];
        }
        if($largest['first'] != $numbersArray[$i] && $largest['second'] != $numbersArray[$i] && $largest['third'] < $numbersArray[$i]){
            $largest['third'] = $numbersArray[$i];
        }

    }
    $percentMargin =  ($largest['first'] *0.8);
    // echo "First Largest updated = ".$largest['first']."<br>";
    // echo "Second Largest updated = ".$largest['second']."<br>";
    // echo "Third Largest updated = ".$largest['third']."<br>";
    // echo "0.8 times 2nd Largest = ".(0.8 * $largest['first'])."<br>";
    if( $percentMargin >= $largest['second']){
        //echo "As First largest is greater than second largest by 20%. So <br>";
        return array('third' => $largest['third'], 'first' => $largest['first']);
    }
}

$largest = calculationThird($numbersArray);
echo print_r($largest);

exit();