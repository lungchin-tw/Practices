// Try: tsc ./src/test-init-array/test-init-array.ts --outDir ./build/test-init-array

function testInitArray(): void {
    const builder = function (value:string): HTMLParagraphElement {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = value;
        return p
    }

    const app = document.getElementById("app")!
    const NUM = 1000000

    {
        const start = new Date().getTime();
        let a1:number[] = new Array(NUM)
        for (let index = 0; index < a1.length; index++) {
            a1[index] = index;
        }

        const elapsed = new Date().getTime() - start
        app.appendChild(builder(`A1(${a1.length}) Elapsed: ${elapsed}`))
    }

    {
        const start = new Date().getTime();
        let a2:number[] = new Array()
        for (let index = 0; index < NUM; index++) {
            a2.push(index)
        }

        const elapsed = new Date().getTime() - start
        app.appendChild(builder(`A2(${a2.length}) Elapsed: ${elapsed}`))
    }
}

testInitArray();