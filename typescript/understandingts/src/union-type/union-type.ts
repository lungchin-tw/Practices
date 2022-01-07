// Try: tsc ./union-type/union-type.ts --outDir ./build/union-type

function testUnionType(): void {
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

    const app = document.getElementById("app")!
    for (const role of person.role) {
        app.appendChild(buildParagraphElement(role))
    }
}

function buildParagraphElement( value: string | number ): HTMLParagraphElement {
    const p = document.createElement("p")
    p.textContent = `Role: ${value}, Type: ${typeof value}`;
    return p
}

testUnionType();