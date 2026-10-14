-- Write your PostgreSQL query statement below
with cte as(
    select L.book_id,
        L.title,L.author,L.genre,L.publication_year,
        count(B.record_id) as current_borrowers,L.total_copies
        from
    library_books L left join borrowing_records B
    on L.book_id=B.book_id
    WHERE B.return_date IS NULL
    group by L.book_id,
        L.title,L.author,L.genre,L.publication_year,L.total_copies
)

select  distinct C.book_id,
        C.title,C.author,C.genre,C.publication_year,
        C.current_borrowers from cte C
where current_borrowers=total_copies
order by current_borrowers desc,title;

