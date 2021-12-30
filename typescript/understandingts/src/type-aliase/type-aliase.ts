// Try: tsc ./literal-type/literal-type.ts --outDir ./build/literal-type

enum TypeAliaseRole { ADMIN, DEVELOPER, GUEST, GOD='GOD' };

type RoleUnion = TypeAliaseRole.ADMIN | TypeAliaseRole.GOD;

function testTypeAliase(): void {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: RoleUnion,
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:TypeAliaseRole.GOD,
    }

    const container = document.getElementById("app")
    container?.appendChild(buildParagraphElementByTypeAliase(person.role))
}


function buildParagraphElementByTypeAliase( value: RoleUnion ): HTMLParagraphElement {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = `TypeAliaseRole[${TypeAliaseRole[value]}]: ${value}`;
    return p
}

testTypeAliase();