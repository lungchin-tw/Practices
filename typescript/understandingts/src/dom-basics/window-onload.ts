// Try: tsc ./src/dom-basics/window-onload.ts --outDir ./build/dom-basics

window.onload = function () {
    console.log("window.onload");
    const heading = document.createElement("h1");
    const text_node = document.createTextNode("New Head");
    heading.appendChild(text_node);
    document.body.appendChild(heading);

    const text_color = document.getElementById("text-color")! as HTMLSelectElement
    text_color.addEventListener(
        "change",
        () => {setDocumentBodyAttr('text', text_color.value);},
    );

    const bg_color = document.getElementById("bg-color")! as HTMLSelectElement
    bg_color.addEventListener(
        "change",
        () => {setDocumentBodyAttr('bgColor', bg_color.value);},
    );
}