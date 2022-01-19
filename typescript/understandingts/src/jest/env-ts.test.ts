
function env() {
    console.log(__dirname);
    console.log(__filename);
    console.log(env.name);
}

test('env', env);