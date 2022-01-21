
function env() {
    console.log(__dirname);
    console.log(__filename);
    console.log(env.name);
}

test('env', env);

describe('working suite', () => {
    it('should work', () => {
        expect(true).toBeTruthy();
    })

    it('not work', () => {
        expect(false).toBeFalsy();
    })
})