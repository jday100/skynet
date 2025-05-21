console.log("Hello world!");

process.argv.forEach((value, index) => {
    console.log(`${index}:${value}`);
});