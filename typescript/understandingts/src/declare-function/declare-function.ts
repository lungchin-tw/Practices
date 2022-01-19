// Try: tsc .src/declare-function/declare-function.ts --outDir ./build/declare-function

function testDeclareFunction_Regulare() {
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


testDeclareFunction_Regulare();