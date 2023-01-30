const answer=Math.floor(Math.random() * 20 + 1);
let guesses=0;

document.getElementById("submitButton").onclick=function (){
    let guess=document.getElementById("guessField").value;
    guesses+=1;
    if (guess==answer){
        alert("Печелиш!", guesses ,"опита");
    }
    else{
        if (guess<answer){
            alert("По-голямо!");
        }
        else{
            alert("По-малко!");
        }
    }
}