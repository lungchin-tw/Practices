// Try: tsc ./array-type/array-type.ts --outDir ./build/array-type

function testArrayType() {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
    }

    const container = document.getElementById("container")
    for (const hobby of person.hobbies) {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = "Hobby: " + hobby;
        container?.appendChild(p)
    }
}

testArrayType();