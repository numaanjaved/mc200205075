<?php 
echo "Seventh<br>"; 
// Given 3 int values, a b c, return their sum. However, if one of the values is the same as another of the values, it does not count towards the sum. 

// lone_sum(1, 2, 3) → 6
// lone_sum(3, 2, 3) → 2
// lone_sum(3, 3, 3) → 0

function lone_sum($a, $b, $c){
    if($a == $b && $a == $c){
        $sum = 0;
    }
    elseif($a == $b){
        $sum = $c;
    }
    elseif($a == $c){
        $sum = $b;
    }
    elseif($b == $c){
        $sum = $a;
    }
    else{
        $sum = $a + $b + $c;
    }
    return $sum;
}

echo lone_sum(1, 2, 3)."<br>";
echo lone_sum(3, 2, 3)."<br>";
echo lone_sum(3, 3, 3)."<br>";



exit();