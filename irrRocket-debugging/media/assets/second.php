<rml>
	<head>
		<title>Second page</title>
		<link type="text/template" href="window.rml" />
		<style>
			body
			{
				width: 400px;
				height: 325px;

				margin: auto;
			}

			div#title_bar div#icon
			{
				display: none;
			}

			div#content
			{
				text-align: left;
			}

            .slider {
                height: 20px;
            }


		</style>
	</head>

	<body template="window">
        <p>Second RML</p>
        <p>Custom content for second.rml</p>
        <?php
            echo "<p id='date'>Current date: ";
            echo date('Y-m-d H:i:s');
            echo "</p>";
         ?>

        <button onclick="first" id="button-first" type="button">Load first.rml</button> <br></br>
        <button onclick="third" id="button-third" type="button">Load third.rml</button> <br></br>

        <input class="slider" type="range" min=1 max=10 step=1>
        </input>
        <br></br>
        <input type="radio" checked="true"/> Radio 1
        <input type="radio"/> Radio 2<br></br>
        <input type="checkbox" checked="true"/> Checkbox 1
        <input type="checkbox"/> Checkbox 2<br></br>
    </body>
</rml>

