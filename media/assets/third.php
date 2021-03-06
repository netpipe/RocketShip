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


		</style>
	</head>

	<body template="window">
		<tabset>
			<tab id="first-tab">Tab 1</tab>
			<panel>
                <p>First RML</p>
                <p>Custom content for first.rml</p>
                <?php
                    echo "<p id='date'>Current date: ";
                    echo date('Y-m-d H:i:s');
                    echo "</p>";
                 ?>

                <form id="form" onsubmit="input">
                    <textarea id="textarea" cols="20" rows="2"/>
                    <input type="submit">Print to console</input>
                </form>

                <img src="clouds.jpg" alt="image"/>
			</panel>
			<tab id="second-tab">Tab 2</tab>
			<panel>
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
			</panel>
            <tab id="third-tab">Tab 3</tab>
			<panel>
                <p>Third RML</p>
                <p>Custom content for third.rml</p>
                <?php
                    echo "<p id='date'>Current date: ";
                    echo date('Y-m-d H:i:s');
                    echo "</p>";
                 ?>
			</panel>
		</tabset>

    </body>
</rml>

