test('declare-function-regular', () =>  {
    function sum(a: number, b: number):number {
        return a + b;
    }

    expect(sum(1,2)).toBe(3);
    expect(([1,2]).reduce(sum)).toBe(3);
})

test('function-expression', () =>  {
    const sum = function (a: number, b: number):number {
        return a + b;
    }

    expect(sum(1,2)).toBe(3);
    expect(([1,2]).reduce(sum)).toBe(3);
})

test('function-declaration-in-conditionals', () =>  {
    const choice = false
    const which_ok = (function(which:boolean) {
        if (which) {
            return function() {
                return 'true ok';
            }
        } else {
            return function() {
                return 'false ok';
            }
        }
    })(choice);
    
    console.log(`${expect.getState().currentTestName}: ${which_ok()}`);
})

test('shorthand-method-definition', () =>  {
})