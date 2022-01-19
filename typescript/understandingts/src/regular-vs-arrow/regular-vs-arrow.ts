// Try: tsc .src/regular-vs-arrow/regular-vs-arrow.ts --outDir ./build/regular-vs-arrow

function testRegularVsArrow() {
    class Hero {
        name: string;
        constructor(name: string) {
            this.name = name;
        }

        regularName() {
            console.log(this.name);
        }

        arrowName = () => {
            console.log(this.name);
        }
    }

    const SuperWoman = new Hero("SuperWoman")

    setTimeout(SuperWoman.regularName, 1000)
    setTimeout(SuperWoman.regularName.bind(SuperWoman), 2000)
    setTimeout(SuperWoman.arrowName, 3000)
}


testRegularVsArrow();