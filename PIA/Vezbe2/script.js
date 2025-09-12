//nizovi

let niz = [2,3,4,5]
niz[4] = 4
niz.push(5) //stavlja na kraj

for(i=0; i<niz.length; i++){
    console.log(niz[i])
}

niz.push(1)
niz.sort((a,b)=>{
    return a-b
})

console.log("Sortirano" + niz)



//rad sa datumima

d1 = new Date()
d2 = new Date(2025, 9, 21)


console.log(d1.getFullYear())
console.log(d1.getMonth())
console.log(d1.getDate())
console.log(d1.getDay())

/*if(d1>d2){
    alert("vece")
}
else alert("vece d2")*/

//setTimeout("hello()", 3000) //pozivam fju posle 3 sec
//iz nekog razloga treba u zagradi da stoji




//Cuvanje podatka - kolacici

localStorage.setItem("mejl", "pera@gmail.com") //key-value
localStorage.setItem("mejl", "cekavicok@gmail.com")
localStorage.setItem("ime", "goran")
localStorage.setItem("objekat", JSON.stringify(niz)) //moram rucno da pretvorim u string
let niz2 = JSON.parse(localStorage.getItem("objekat")) //vracam u int?

let m = localStorage.getItem("mejl")
let ime = m.split("@")[1]

console.log(ime + " posle @")

console.log(niz2)
console.log(localStorage.getItem("mejl"))

localStorage.removeItem("ime")
//localStorage.clear()







//funkcije
function hello(){
    alert("Hello world fja je pozvana") //samo izadje notifikacija
}


function forma(){
    var ime = document.forma1.ime.value;

    let regexIme = /^[A-Z]\w{3,}$/ //regularni izrazi :(
    let regexMejl = /^\w+@\w{5,10}\.com$/ //primer za mejl neki

    if(!regexIme.test(ime)){
        alert("ime nije oke")
    }

    let boja = document.forma1.boja.value
    let java = document.forma1.java.checked
    let c = document.forma1.c.checked;
    let drzava = document.getElementById("drz").value;


    console.log(ime)
    console.log(boja)
    if(java) alert("JAVA")
    console.log(drzava)
}


