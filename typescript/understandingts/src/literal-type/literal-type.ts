// Try: tsc ./literal-type/literal-type.ts --outDir ./build/literal-type

enum Role { ADMIN, DEVELOPER, GUEST, GOD='GOD' };

function testLiteralType(): void {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: Role.ADMIN | Role.DEVELOPER,
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:Role.ADMIN,
    }

    const container = document.getElementById("app")
    container?.appendChild(buildParagraphElementByLiteralType(person.role))
}


function buildParagraphElementByLiteralType( value: Role.ADMIN | Role.DEVELOPER ): HTMLParagraphElement {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = `Role[${Role[value]}]: ${value}`;
    return p
}

testLiteralType();