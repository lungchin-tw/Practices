
export function AppendChildParagraph(id:string, content:string) {
    const p = document.createElement("p") as HTMLParagraphElement
    p.textContent = content;

    const elem = document.getElementById(id)!
    elem.appendChild(p)
}