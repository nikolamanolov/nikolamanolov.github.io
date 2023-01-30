
const myLabel=document.getElementById("myLabel");

update();
setInterval(update, 1000);
function update(){

    let date=new Date();
    myLabel.innerHTML=formatTime(date);

    function formatTime(date){
        let hours=date.getHours();
        let minutes=date.getMinutes();
        let seconds=date.getSeconds();
        
        

        return `${hours}:${minutes}:${seconds}`;
    }
}