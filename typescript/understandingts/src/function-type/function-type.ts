// Try: tsc ./function-type/function-type.ts --outDir ./build/function-type

enum FuncTypeRole { ADMIN, DEVELOPER, GUEST, GOD='GOD' };

type FuncTypeUnion = FuncTypeRole.ADMIN | FuncTypeRole.GUEST;
type FuncTypeBuildParagraphElement = (value: FuncTypeUnion) => HTMLParagraphElement;

function testFunctionType(): void {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: FuncTypeUnion,
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:FuncTypeRole.GUEST,
    }

    let builder: FuncTypeBuildParagraphElement = testFunctionType_buildParagraphElement

    const container = document.getElementById("app")
    container?.appendChild(builder(person.role))
}


function testFunctionType_buildParagraphElement( value: FuncTypeUnion ): HTMLParagraphElement {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = `FuncTypeRole[${FuncTypeRole[value]}]: ${value}`;
    return p
}

testFunctionType();