<rml>
	<head>
		<title>First page</title>
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

            #navbar {
                width: 100%;
                height: 50px;
                background-color: #1976d2;
			}

			.dropdown-container {
                float: left;
                width: 150px;
			}

            .sub-dropdown-container {
                display: none;
                position: absolute;
                float: left;
                margin-left: 150px;
                margin-top: 44px;
			}

			.dropdown-content {
                display: none;
                width: 150px;
                background-color: #1976d2;
                border-width: 1px;
                border-color: #004ba0;
                padding: 0px;
			}

            button {
                color: white;
                float: left;
                width: 150px;
                shadow-font-effect: shadow;
                shadow-offset: 1px 1px;
                shadow-color: black;
			}

			p {
                z-index: -1;
			}

			img {
			}

			#textarea {
                border-width: 1px;
                background-color: white;
                color: black;
                z-index: -1;
			}

		</style>
	</head>

	<body template="window">

        <div id="navbar">
            <div class="dropdown-container">
                <button onclick="dropdown" class="dropdown-button" id="dropdown-button" type="button">Dropdown</button>
                <div class="dropdown-content" id="dropdown-content">
                    <button id="sites" type="button" onclick="sub-dropdown">Sites ></button>
                    <div class="sub-dropdown-container dropdown-content" id="sub-dropdown">
                        <button onclick="second" id="button-second" type="button">Load second.rml</button>
                        <button onclick="third" id="button-third" type="button">Load third.rml</button>
                    </div>
                    <button onclick="third" id="button-third" type="button">Load third.rml</button>
                </div>
            </div>
            <div class="dropdown-container">
                <button onclick="dropdown" class="dropdown-button" id="dropdown-button-2" type="button">Dropdown 2</button>
                <div class="dropdown-content" id="dropdown-content-2">
                    <button onclick="second" id="button-second" type="button">Load second.rml</button>
                    <button onclick="third" id="button-third" type="button">Load third.rml</button>
                </div>
            </div>
        </div>

        <p>First RML</p>
        <?php
            echo "<p id='date'>Current date: ";
            echo date('Y-m-d H:i:s');
            echo "</p>";
         ?>

        <button onclick="third" id="open-button" type="button">Open third.rml</button>

        <form id="form" onsubmit="input">
            <textarea id="textarea" cols="20" rows="2"/>
			<input type="submit">Print to console</input>
		</form>

        <p>Click on the image to load second.rml</p>
        <img src="clouds.jpg" alt="image"/>

    </body>
</rml>

