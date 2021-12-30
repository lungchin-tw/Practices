// Try: tsc ./callback/callback.ts --outDir ./build/callback

enum CallBackRole { ADMIN, DEVELOPER, GUEST, CALLBACK, GOD='GOD' };

type CallBackUnion = CallBackRole.ADMIN | CallBackRole.GUEST | CallBackRole.CALLBACK;
type CallBackBuildParagraphElement = (value: CallBackUnion) => HTMLParagraphElement;

function testCallBack(builder: CallBackBuildParagraphElement): void {
    const person: {
        name: string;
        age: number;
        hobbies: string[],
        role: CallBackUnion,
    } = {
       name: "Vivian",
       age: 50,
       hobbies: ["Watching TV", "Shopping", "Playing Card Games"],
       role:CallBackRole.CALLBACK,
    }

    const container = document.getElementById("app")
    container?.appendChild(builder(person.role))
}

function testCallBack_buildParagraphElement( value: CallBackUnion ): HTMLParagraphElement {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = `CallBackRole[${CallBackRole[value]}]: ${value}`;
    return p
}

testCallBack(testCallBack_buildParagraphElement);