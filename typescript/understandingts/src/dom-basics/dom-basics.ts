// Try: tsc ./src/dom-basics/dom-basics.ts --outDir ./build/dom-basics


function testDOMBasics(): void {
    const p = document.createElement("p");
    p.textContent = "Hello, World!";
    document.getElementById("app")!.appendChild(p);

    const ul = document.getElementsByTagName("ul")[0]
    console.log("ul.children: ", ul.children)
    console.log("ul.childNodes: ", ul.childNodes)

    console.log("document.querySelector('li'):", document.querySelector("li"))
    console.log("document.querySelectorAll('li'):", document.querySelectorAll("li"))
}

testDOMBasics();

function setDocumentBodyAttr(attr: string, value: string) {
    console.log(`setDocumentBodyAttr(Attr:${attr}, Value:${value})`);
    if (document.body) {
        document.body.setAttribute(attr, value);
    } else {
        throw new Error("No Support!!!");
        
    }
    
}