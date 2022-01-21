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
    
    expect(which_ok()).toBe('false ok');
})

test('computed-property-names-and-methods', () =>  {
    const adder = 'add', getter = 'get';
    const collection = {
        items: [],
        [adder](...items:any) {
            this.items.push(...items);
        },

        [getter](index: number): any {
            return this.items[index]
        }
    };
    collection[adder]('A', 'B', 'C')
    expect(collection.items).toHaveLength(3);
    expect(collection[getter](1)).toBe('B') ;
})

test('generator-function', () =>  {
    function* indexGenerator() {
        let index: number = 0
        while(true) {
            yield index++;
        }
    }

    const gen = indexGenerator();
    expect(gen.next().value).toBe(0);
    expect(gen.next().value).toBe(1);
})

test('new-function', () =>  {
    const a = 'a', b = 'b';
    const sum = new Function(a, b, 'return a + b');
    expect(sum(10, 15)).toBe(25);
})