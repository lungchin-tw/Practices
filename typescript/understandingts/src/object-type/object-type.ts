// Try: tsc ./object-type/object-type.ts --outDir ./build/object-type

function testObjectType() {
    const person: {
        name: string;
        age: number;
    } = {
       name: "Vivian",
       age: 50,
    }

    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = "Name: " + person.name;
    document.getElementById("container")?.appendChild(p)
}

testObjectType();