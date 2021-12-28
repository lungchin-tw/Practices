// Try: tsc ./enum-type/enum-type.ts --outDir ./build/enum-type

function testEnumType() {
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
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = "Role: " + role;
        container?.appendChild(p)
    }

    for (const key in Role) {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = `Role[${key}] = ${Role[key]}`
        container?.appendChild(p)
    }
}

testEnumType();