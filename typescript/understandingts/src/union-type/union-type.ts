// Try: tsc ./union-type/union-type.ts --outDir ./build/union-type

function testUnionType() {
    enum Role { ADMIN, DEVELOPER, GUEST, GOD='GOD' };
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: [Role, string],
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:[Role.DEVELOPER, "Mom"]
    }

    const container = document.getElementById("container")
    for (const role of person.role) {
        container?.appendChild(buildParagraphElement(role))
    }
}

function buildParagraphElement( value: string | number ) {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = `Role: ${value}, Type: ${typeof value}`;
    return p
}

testUnionType();