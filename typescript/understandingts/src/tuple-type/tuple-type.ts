// Try: tsc ./tuple-type/tuple-type.ts --outDir ./build/tuple-type

function testTupleType() {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: [number, string],
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:[2, "Mom"]
    }

    const container = document.getElementById("container")
    for (const role of person.role) {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = "Role: " + role;
        container?.appendChild(p)
    }
}

testTupleType();