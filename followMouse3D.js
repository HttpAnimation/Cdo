window.onload = function() {
    var title = document.getElementById('title');

    // Mousemove event listener to handle 3D effect
    document.addEventListener('mousemove', function(e) {
        var mouseX = e.clientX;
        var mouseY = e.clientY;
        var titleRect = title.getBoundingClientRect();
        var titleCenterX = titleRect.left + titleRect.width / 2;
        var titleCenterY = titleRect.top + titleRect.height / 2;

        var dx = mouseX - titleCenterX;
        var dy = mouseY - titleCenterY;

        // Adjusting rotation angles based on mouse position
        title.style.transform = 'perspective(1000px) rotateY(' + (-dx / 10) + 'deg) rotateX(' + (dy / 10) + 'deg)';
    });
}
