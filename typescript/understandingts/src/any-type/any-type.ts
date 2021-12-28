// Try: tsc ./any-type/any-type.ts --outDir ./build/any-type

function testAnyType() {
    enum Role { ADMIN, DEVELOPER, GUEST, GOD='GOD' };
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: any[],
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:[Role.DEVELOPER, "Mom"]
    }

    const container = document.getElementById("container")
    for (const role of person.role) {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = `Role: ${role}, Type: ${typeof role}`;
        container?.appendChild(p)
    }
}

testAnyType();