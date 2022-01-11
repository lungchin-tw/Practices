// Try: tsc ./src/time-utils/time-utils.ts --outDir ./build/time-utils


function testTimeUtils(): void {
    const builder = function (value:string): HTMLParagraphElement {
        const p = document.createElement("p") as HTMLParagraphElement
        p.textContent = value;
        return p
    }

    const app = document.getElementById("app")!

    // Unit: Millisecond
    app.appendChild(builder("Date().getTime(): " + new Date().getTime()))
    app.appendChild(builder("Date().valudOf(): " + new Date().valueOf()))
}



testTimeUtils();