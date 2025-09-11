function paragraph_edit() {
        var border_red = document.getElementById("border_red").value;
        var border_green = document.getElementById("border_green").value;
        var border_blue = document.getElementById("border_blue").value;
        var paragraph_red = document.getElementById("paragraph_red").value;
        var paragraph_green = document.getElementById("paragraph_green").value;
        var paragraph_blue = document.getElementById("paragraph_blue").value;
        var border_width = document.getElementById("border_width").value;
        var tag = document.getElementById("paragraph");
        tag.style.borderColor = `rgb(${border_red},${border_green},${border_blue})`;
        tag.style.backgroundColor = `rgb(${paragraph_red},${paragraph_green},${paragraph_blue})`;
        tag.style.borderWidth = border_width
    }