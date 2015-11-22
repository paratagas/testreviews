<?php

/**
 * @file
 * Contains testreviews block functions.
 */
	
/**
 * Creates reviews list for testreviews-block.tpl.php.
 */
function testreviews_create_reviews_list() {
    $query = db_select('testreviews', 'tr')
      ->fields('tr')
      // для примера выводим только опубликованные отзывы
      ->condition('published', 1)
      ->orderBy('id', 'DESC')
      ->execute();
    
    $rows = false;
    
    while($value = $query->fetchAssoc())
    {
        $rows[] = array(
            $value['id'],
            $value['title'],
            $value['category'],
            $value['actuality']
        );
    }
    
    // если отзывы есть - возвращаем их массив, иначе - false
    return $rows;
}