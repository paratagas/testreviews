<div id = "testreviews-list">
    <?php
    $reviews = testreviews_create_reviews_list();
    // если $reviews - массив, выводим таблицу
    // тогда сообщение: "Here's the list of published reviews"
    if($reviews):
    ?>
    <h3><?php echo $reviews_message['has_reviews']; ?></h3>
    
    <table class="testreviews-table">
        <thead>
            <tr>
                <th>№</th>
                <th>Title</th>
                <th>Category</th>
                <th>Actuality</th>
            </tr>
        </thead>
        <tbody>
            <?php
            $reviews_count = 1;
            foreach($reviews as $review):
            ?>
            <tr>
                <td><?php echo $reviews_count; ?></td>
                
                <td>
                <?php
                // при различиях в настройках маршрутизации, возможно,
                // придется изменить значение атрибута a href: часть строки ниже
                // с "?q=", например, на "/"
                ?>
                <a href="?q=testreviews-page/<?php echo $review[1]; ?>&id=<?php echo $review[0]; ?>"><?php echo $review[1]; ?></a>
                </td>
    
                <td><?php echo $review[2]; ?></td>
                <td><?php echo $review[3]; ?></td>
            </tr>
            <?php
                $reviews_count++;
            endforeach;
            ?>
        <tbody>
    </table>
    <?php
        // если $reviews - false, таблицу не выводим
        // тогда сообщение: "There's no published reviews yet" 
	   else:
    ?>
    <h3><?php echo $reviews_message['no_reviews']; ?></h3>
    <?php
	   endif;
    ?>
</div>