$(document).ready(function() {
    $("p").hide();
    $("h1").click(function() {
        $(this).next().slideToggle(300);
    });

    $("#test-button-I").click(function() {
        $("strong, #test-button-II").css( "background-color", "gray");
    });

    $("#test-button-II").click(function() {
        $("div > p").css( "background-color", "purple");
        $(this).css( "background-color", "orange");
    });
});