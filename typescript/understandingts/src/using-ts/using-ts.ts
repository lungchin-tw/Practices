// Try: tsc ./using-ts/using-ts.ts --outDir ./build/using-ts

const tsbutton = document.querySelector("button")!
const tsinput1 = document.getElementById("num1")! as HTMLInputElement
const tsinput2 = document.getElementById("num2")! as HTMLInputElement

function tsadd(num1: number, num2: number) {
    console.log("typeof num1: " + typeof num1)
    return num1 + num2
}

tsbutton.addEventListener("click", function() {
    let n1: number = +tsinput1.value
    let n2: number = +tsinput2.value
    let result:number = tsadd(n1, n2)

    const p = document.createElement("p") as HTMLParagraphElement    
    p.textContent = "result: " + result.toString(10)
    document.getElementById("container")?.appendChild(p)
});